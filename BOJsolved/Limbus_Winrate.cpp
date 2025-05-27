#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sinner
{
private:
    string sinner_name;
    int mental;
    int health;
    int base_power;
    int coin;
    int value_per_coin;

public:
    Sinner(string sinner_name, int base_power, int coin, int value_per_coin, int menatl):
    sinner_name(sinner_name), 
    base_power(base_power), 
    coin(coin), 
    value_per_coin(value_per_coin),
    mental(0),
    health(0)
    {}

    string get_sinner_name();
    int get_final_power();
    double get_coin_probability();
    void win_clash(int clash_count);
    void use_ego(int ego_mental);
    int get_coin();
};

string Sinner::get_sinner_name(){
    return sinner_name;
}

double Sinner::get_coin_probability()
{
    return static_cast<double>(mental + 45) / 90.0;  
}

int Sinner::get_final_power()
{
    int power = base_power;
    double probability = get_coin_probability();
    for(int i=0; i<coin; i++){
        if((rand() / static_cast<double>(RAND_MAX)) < probability){ 
            power += value_per_coin;
        }
    }
    return power;
}

void Sinner::win_clash(int clash_count)
{
    mental = min(45, static_cast<int>(round(mental + 10 + clash_count * 2.5)));
}

int Sinner::get_coin()
{
    return coin;
}

void Sinner::use_ego(int ego_mental)
{   
    if(mental - ego_mental > -45){
        mental = max(-45, mental - ego_mental);
    }else{
        cout << "침식 발생..." << '\n';
    }
}

int clash(Sinner &sin1, Sinner &sin2)
{
    int sin1_power = sin1.get_final_power();
    int sin2_power = sin2.get_final_power();
    int clash_count = 0;
    
    if(sin1_power == sin2_power){
        clash_count++;
        return 0;
    }else if(sin1_power > sin2_power){
        clash_count++;
        return 1;
    }else{
        clash_count++;
        return 2;
    }
}

void simulate_battle(Sinner &sin1, Sinner &sin2, int simulate_count)
{
    int sin1_wins = 0;

    for(int i=0; i<simulate_count; i++){
        int sin1_coins = sin1.get_coin();
        int sin2_coins = sin2.get_coin();

        while(sin1_coins > 0 && sin2_coins > 0){
            int winner = clash(sin1, sin2);
            if(winner == 1){
                sin2_coins--;
            } else if(winner == 2){
                sin1_coins--;
            }
        }
        if(sin2_coins == 0){
            sin1_wins++;
        }
    }
    cout << sin1.get_sinner_name() << "가 " << simulate_count << "번 중 " << sin1_wins << "번 승리" << '\n';
    cout << sin2.get_sinner_name() << "가 " << simulate_count << "번 중 " << simulate_count - sin1_wins << "번 승리" << '\n';
}

int main(){
    srand(time(NULL));
    Sinner sinner1("수감자", 10, 2, 5, 0);
    Sinner sinner2("환상체", 8, 3, 4, 0);
    simulate_battle(sinner1, sinner2, 1000);
}
