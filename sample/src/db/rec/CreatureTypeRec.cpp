// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/CreatureTypeRec.hpp"
#include "util/SFile.hpp"

const char* CreatureTypeRec::GetFilename() {
    return "DBFilesClient\\CreatureType.dbc";
}

uint32_t CreatureTypeRec::GetNumColumns() {
    return 19;
}

uint32_t CreatureTypeRec::GetRowSize() {
    return 76;
}

bool CreatureTypeRec::NeedIDAssigned() {
    return false;
}

int32_t CreatureTypeRec::GetID() {
    return this->m_ID;
}

void CreatureTypeRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool CreatureTypeRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t nameOfs[16];
    uint32_t nameMask;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[6], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[7], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[8], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[9], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[10], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[11], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[12], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[13], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[14], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs[15], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameMask, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_flags, sizeof(this->m_flags), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_name = &stringBuffer[nameOfs[CURRENT_LANGUAGE]];
    } else {
        this->m_name = "";
    }

    return true;
}
