// #pragma once
// #include <iostream>
// #include "NPC.h"
// #include "Dragon.h"
// #include "Knight.h"
// #include "BlackKnight.h"
// class Dragon : NPC{

// };


// class Visitor{
//     public:
//         bool visit(Dragon* attacker, NPC* defender){
//             try{
//                 Dragon* def = dynamic_cast<Dragon*>(defender);
//                 // функция драки
//                 return false;
//             }
//             catch(...){
//                 std::cout << "\n";
//             }

//             try{
//                 Knight* def = dynamic_cast<Knight*>(defender);
//                 // функция драки
//                 return true;
//             }
//             catch(...){
//                 std::cout << "\n";
//             }

//             try{
//                 BlackKnight* def = dynamic_cast<BlackKnight*>(defender);
//                 // функция драки
//                 return true;
//             }
//             catch(...){
//                 std::cout << "\n";
//             }

//             throw std::runtime_error("Unrecognised NPC joined the party");

//         }

//     // bool visit(Knight attacker, NPC* defender){
        
//     // }

//     // bool visit(BlackKnight attacker,  NPC* defender){
        
//     // }
// };