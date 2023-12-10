#include "NPC.h"
#include "math.h"
#include <shared_mutex>

std::mutex mtx;

NPC::NPC(Point p){
    this->location = p;
}

NPC::NPC(){
    this->location = {0, 0};   
}

bool NPC::isClose(const NPC* other, size_t distance)
{
    std::lock_guard<std::mutex> lck(mtx);
    if (std::pow(this->location.getX() - other->location.getX(), 2) + std::pow(this->location.getY() - other->location.getY(), 2) <= std::pow(distance, 2))
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << npc.location;
    return os;
}

Point NPC::getLocation(){
    // std::lock_guard<std::mutex> lck(this->mtx);
    return this->location;
}

std::string NPC::getName() const {
    return this->name;
}

void NPC::move(int shift_x, int shift_y, int max_x, int max_y){
    std::lock_guard<std::mutex> lck(this->mtx);
    if ((this->location.getX() + shift_x >= 0) &&(this->location.getX() + shift_x <= max_x)){
        this->location.setX(this->location.getX() + shift_x);
    }
    if ((this->location.getY() + shift_y >= 0) &&(this->location.getY() + shift_y <= max_y)){
        this->location.setY(this->location.getY() + shift_y);
    }
}

bool NPC::is_alive(){
    std::lock_guard<std::mutex> lck(this->mtx);
    return this->alive;
}

void NPC::kill(){
    std::lock_guard<std::mutex> lck(this->mtx);
    this->alive = false;
}

int NPC::getKillDistance(){
    return this->kill_distance;
}


