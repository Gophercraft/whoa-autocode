// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/GemPropertiesRec.hpp"
#include "util/SFile.hpp"

const char* GemPropertiesRec::GetFilename() {
    return "DBFilesClient\\GemProperties.dbc";
}

uint32_t GemPropertiesRec::GetNumColumns() {
    return 5;
}

uint32_t GemPropertiesRec::GetRowSize() {
    return 20;
}

bool GemPropertiesRec::NeedIDAssigned() {
    return false;
}

int32_t GemPropertiesRec::GetID() {
    return this->m_ID;
}

void GemPropertiesRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool GemPropertiesRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_enchantID, sizeof(this->m_enchantID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_maxcountInv, sizeof(this->m_maxcountInv), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_maxcountItem, sizeof(this->m_maxcountItem), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_type, sizeof(this->m_type), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
