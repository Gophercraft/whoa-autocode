// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/DeathThudLookupsRec.hpp"

const char* DeathThudLookupsRec::GetFilename() {
    return "DBFilesClient\\DeathThudLookups.dbc";
}

bool DeathThudLookupsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SizeClass, sizeof(this->m_SizeClass), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_TerrainTypeSoundID, sizeof(this->m_TerrainTypeSoundID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundEntryID, sizeof(this->m_SoundEntryID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundEntryIDWater, sizeof(this->m_SoundEntryIDWater), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}