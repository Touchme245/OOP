#include <iostream>
#include <map>
#include "DeathAgregator.h"
#include "Dragon.h"
#include "ConsoleWriter.h"
#include "Observer.h"

int main(){
    DeathAgregator deathAgregator; 
    //= new DeathAgregator();
    Dragon* d1 = new Dragon({5,2});
    ConsoleWriter* writer = new ConsoleWriter(); 


    deathAgregator.subscribe(dynamic_cast<Observer* >(writer));

    deathAgregator.notify(dynamic_cast<NPC* >(d1));
    
}