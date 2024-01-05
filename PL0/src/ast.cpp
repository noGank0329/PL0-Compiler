#include "ast.h"

void ConstDecl::addConstDef(ConstDef *def) {
    ConstDefs.insert({def->id->getId(), def});
}

ConstDef *ConstDecl::getConstDef(Identifier *id) {
    if (ConstDefs.find(id->getId()) == ConstDefs.end()) return nullptr;
    return ConstDefs[id->getId()];
}

void VarDecl::addVarDef(Identifier *id) {
    VarDefs.insert({id->getId(), id});
}

bool VarDecl::hasThisVarDef(Identifier *id) {
    return VarDefs.find(id->getId()) != VarDefs.end();
}

