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
        NPC* createNPC(NpcType type, double x, double y){
            switch (type){
                case DragonType:
                    Dragon dragon = new Dragon({x % fieldSizeX, y % fieldSizeY});
                    return dynamic_cast<NPC*>(dragon);
                    break;
                case KnightType:
                    Knight knight = new Knight({x % fieldSizeX, y % fieldSizeY});
                    return dynamic_cast<NPC*>(knight);
                    break;
                case BlackKnightType:
                    BlackKnight blackKnight = new BlackKnight({x % fieldSizeX, y % fieldSizeY});
                    return dynamic_cast<NPC*>(blackKnight);
                    break;
                default:
                    break;
            }
        }
}