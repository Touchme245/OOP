#include <Visitor.h>


bool DragonVisitor::visit(const Dragon& dragon){
    return false;
}

bool DragonVisitor::visit(const BlackKnight& black){
    srand(time(nullptr));
    int attack = std::rand() % 6;
    int def = std::rand() % 6;
    if (attack> def){
        return true;
    }
    return false;
}

bool DragonVisitor::visit(const Knight& knight){
    return false;
    
}

bool DragonVisitor::visit(const Sukuna& sukuna){
    return false;
    
}

bool KnightVisitor::visit(const Dragon& dragon){
    srand(time(nullptr));
    int attack = std::rand() % 6;
    int def = std::rand() % 6;
    if (attack> def){
        return true;
    }
    return false;
}

bool KnightVisitor::visit(const BlackKnight& black){
    srand(time(nullptr));
    int attack = std::rand() % 6;
    int def = std::rand() % 6;
    if (attack> def){
        return true;
    }
    return false;
}

bool KnightVisitor::visit(const Knight& knight){
    return false;
    
}

bool KnightVisitor::visit(const Sukuna& sukuna){
    return false;
    
}

bool BlackKnightVisitor::visit(const Dragon& dragon){
    return false;
}

bool BlackKnightVisitor::visit(const BlackKnight& black){
    return false;
}

bool BlackKnightVisitor::visit(const Knight& knight){
    srand(time(nullptr));
    int attack = std::rand() % 6;
    int def = std::rand() % 6;
    if (attack> def){
        return true;
    }
    return false;
    
}

bool BlackKnightVisitor::visit(const Sukuna& sukuna){
    return false;
    
}

bool SukunaVisitor::visit(const Sukuna& sukuna){
    return false;
}

bool SukunaVisitor::visit(const Dragon& dragon){
    return true;
}

bool SukunaVisitor::visit(const Knight& knight){
    return true;
}

bool SukunaVisitor::visit(const BlackKnight& sublackkuna){
    return true;
}

