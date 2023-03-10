// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/NamesProfanityRec.hpp"
#include "util/SFile.hpp"

const char* NamesProfanityRec::GetFilename() {
    return "DBFilesClient\\NamesProfanity.dbc";
}

uint32_t NamesProfanityRec::GetNumColumns() {
    return 3;
}

uint32_t NamesProfanityRec::GetRowSize() {
    return 12;
}

bool NamesProfanityRec::NeedIDAssigned() {
    return false;
}

int32_t NamesProfanityRec::GetID() {
    return this->m_ID;
}

void NamesProfanityRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool NamesProfanityRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t nameOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_language, sizeof(this->m_language), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_name = &stringBuffer[nameOfs];
    } else {
        this->m_name = "";
    }

    return true;
}
