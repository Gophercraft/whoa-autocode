// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/ItemGroupSoundsRec.hpp"
#include "util/SFile.hpp"

const char* ItemGroupSoundsRec::GetFilename() {
    return "DBFilesClient\\ItemGroupSounds.dbc";
}

uint32_t ItemGroupSoundsRec::GetNumColumns() {
    return 5;
}

uint32_t ItemGroupSoundsRec::GetRowSize() {
    return 20;
}

bool ItemGroupSoundsRec::NeedIDAssigned() {
    return false;
}

int32_t ItemGroupSoundsRec::GetID() {
    return this->m_ID;
}

void ItemGroupSoundsRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool ItemGroupSoundsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_sound[0], sizeof(m_sound[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_sound[1], sizeof(m_sound[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_sound[2], sizeof(m_sound[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_sound[3], sizeof(m_sound[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
