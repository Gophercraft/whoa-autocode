// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellTotemsRec.hpp"
#include "util/SFile.hpp"

const char* SpellTotemsRec::GetFilename() {
    return "DBFilesClient\\SpellTotems.dbc";
}

uint32_t SpellTotemsRec::GetNumColumns() {
    return 5;
}

uint32_t SpellTotemsRec::GetRowSize() {
    return 20;
}

bool SpellTotemsRec::NeedIDAssigned() {
    return false;
}

int32_t SpellTotemsRec::GetID() {
    return this->m_ID;
}

void SpellTotemsRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool SpellTotemsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_requiredTotemCategoryID[0], sizeof(m_requiredTotemCategoryID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_requiredTotemCategoryID[1], sizeof(m_requiredTotemCategoryID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_totem[0], sizeof(m_totem[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_totem[1], sizeof(m_totem[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
