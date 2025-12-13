// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include "pilot.h"

Pilot::Pilot(const std::string& name) : _name(name) {}

std::string Pilot::getName() const {
    return _name;
}

void Pilot::command() {
    return;
}
