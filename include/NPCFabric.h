#include "NPC.h"
#include "Dragon.h"
#include "Knight.h"
#include "BlackKnight.h"
#include "NPCType.h"

class NPCFabric{
    private:
    int fieldSizeX = 100;
    int fieldSizeY = 100;
    int NPCAmount = 3;
    public:
        static NPC* createNPC(NpcType type, double x, double y){
            Point coords{x,y};
            switch (type){
                case DragonType:
                {
                    Dragon* dragon = new Dragon(coords);
                    return dynamic_cast<NPC*>(dragon);
                    break;
                }
                    
                case KnightType:
                {
                    Knight* knight = new Knight(coords);
                    return dynamic_cast<NPC*>(knight);
                    break;
                }
                    
                case BlackKnightType:
                {
                    BlackKnight* blackKnight = new BlackKnight(coords);
                    return dynamic_cast<NPC*>(blackKnight);
                    break;
                }
                    
                default:
                    break;
            }
        }
};