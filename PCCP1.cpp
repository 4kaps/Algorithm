#include <string>
#include <vector>

using namespace std;

// bandage - [시전시간, 초당 회복량, 추가 회복량]
// attacks - [공격시간, 피해량]

void maxHealth(int *health, int mx){
    if(*health > mx){
        *health = mx;
    }
}

int solution(vector<int> bandage, int mx, vector<vector<int>> attacks) {    
    int last_time = attacks[attacks.size() - 1][0];
    int heal_time = bandage[0];
    int heal_per = bandage[1];
    int heal_bonus = bandage[2];
    int heal_count = 0;
    bool is_attack = false;
    int health = mx;
        
    for(int i=1; i<=last_time; i++){
        is_attack = false;
        for(int j=0; j<attacks.size(); j++){
            if(i == attacks[j][0]){
                is_attack = true;
                heal_count = 0;
                health -= attacks[j][1];
                if(health <= 0){
                    return -1;
                }
                break;
            }
        }
        
        if(!is_attack){
            health += heal_per;
            maxHealth(&health, mx);

            heal_count++;
            if(heal_count == heal_time){
                health += heal_bonus;
                maxHealth(&health, mx);
                heal_count = 0;
            }
        }
    }

    return health;
}
