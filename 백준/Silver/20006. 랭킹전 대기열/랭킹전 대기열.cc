#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Player{
    int level;
    string name;
};

struct Room{
    vector<Player> players;
    int minLevel;
    int maxLevel;
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int p, m;
    cin >> p >> m;
    
    vector<Room> rooms;
    
    while(p--){
        int l;
        string n;
        cin >> l >> n;
        
        Player currentPlayer = {l, n};
        
        bool isJoined = false;
        if(rooms.empty()==false){
            for(auto& room : rooms){
                if(room.players.size()<m && l>=room.minLevel && l<=room.maxLevel){
                    room.players.push_back(currentPlayer);
                    isJoined = true;
                    break;
                }
            }
        }
        
        if(isJoined==false){
            Room newRoom;
            newRoom.players.push_back(currentPlayer);
            newRoom.minLevel = l-10;
            newRoom.maxLevel = l+10;
            
            rooms.push_back(newRoom);
        }  
    }
    
    for(auto& room : rooms){
        if(room.players.size()==m){
            cout << "Started!\n";
        }else{
            cout << "Waiting!\n";
        }
        
        sort(room.players.begin(), room.players.end(), [](const Player& a, const Player& b){return a.name<b.name;});
    
        for(const auto& player : room.players){
            cout << player.level << " " << player.name << "\n";
        }
    }
    return 0;
}