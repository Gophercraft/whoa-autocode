// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellRuneCostRec.hpp"
#include "util/SFile.hpp"

const char* SpellRuneCostRec::GetFilename() {
    return "DBFilesClient\\SpellRuneCost.dbc";
}

uint32_t SpellRuneCostRec::GetNumColumns() {
    return 5;
}

uint32_t SpellRuneCostRec::GetRowSize() {
    return 20;
}

bool SpellRuneCostRec::NeedIDAssigned() {
    return false;
}

int32_t SpellRuneCostRec::GetID() {
    return this->m_ID;
}

void SpellRuneCostRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool SpellRuneCostRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_blood, sizeof(this->m_blood), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_unholy, sizeof(this->m_unholy), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_frost, sizeof(this->m_frost), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_runicPower, sizeof(this->m_runicPower), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
