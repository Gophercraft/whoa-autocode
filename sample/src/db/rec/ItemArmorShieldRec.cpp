// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/ItemArmorShieldRec.hpp"
#include "util/SFile.hpp"

const char* ItemArmorShieldRec::GetFilename() {
    return "DBFilesClient\\ItemArmorShield.dbc";
}

uint32_t ItemArmorShieldRec::GetNumColumns() {
    return 9;
}

uint32_t ItemArmorShieldRec::GetRowSize() {
    return 36;
}

bool ItemArmorShieldRec::NeedIDAssigned() {
    return false;
}

int32_t ItemArmorShieldRec::GetID() {
    return this->m_ID;
}

void ItemArmorShieldRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool ItemArmorShieldRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_itemLevel, sizeof(this->m_itemLevel), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[0], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[1], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[2], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[3], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[4], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[5], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_quality[6], sizeof(m_quality[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
