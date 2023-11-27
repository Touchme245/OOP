#include <Visitor.h>

bool DragonVisitor::visit(const Dragon& dragon){
    return false;
}

bool DragonVisitor::visit(const BlackKnight& black){
    return true;
}

bool DragonVisitor::visit(const Knight& knight){
    return false;
    
}

bool DragonVisitor::visit(const Sukuna& sukuna){
    return false;
    
}

bool KnightVisitor::visit(const Dragon& dragon){
    return true;
}

bool KnightVisitor::visit(const BlackKnight& black){
    return true;
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
    return true;
    
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

