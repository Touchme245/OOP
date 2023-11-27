#pragma once
#include "NPC.h"

class Dragon;
class Knight;
class BlackKnight;
class Sukuna;


class IVisitor {
public:
    virtual bool visit(const Dragon & dragon) = 0;
    virtual bool visit(const Knight & knight) = 0;
    virtual bool visit(const BlackKnight & black) = 0;
    virtual bool visit(const Sukuna & sukuna) =0 ;

};


class DragonVisitor : public IVisitor {
public:
    bool visit(const Dragon & dragon) override;
    bool visit(const Knight & knight) override;
    bool visit(const BlackKnight & black) override;
    bool visit(const Sukuna & sukuna) override;

};


class KnightVisitor : public IVisitor {
public:
    bool visit(const Dragon & dragon) override;
    bool visit(const Knight & knight) override;
    bool visit(const BlackKnight & black) override;
    bool visit(const Sukuna & sukuna) override;

};


class BlackKnightVisitor : public IVisitor {
public:
    bool visit(const Dragon & dragon) override;
    bool visit(const Knight & knight) override;
    bool visit(const BlackKnight & black) override;
    bool visit(const Sukuna & sukuna) override;
};

class SukunaVisitor : public IVisitor {
public:
    bool visit(const Dragon & dragon) override;
    bool visit(const Knight & knight) override;
    bool visit(const BlackKnight & black) override;
    bool visit(const Sukuna & sukuna) override;
};