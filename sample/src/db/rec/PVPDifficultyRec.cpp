// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/PVPDifficultyRec.hpp"

const char* PVPDifficultyRec::GetFilename() {
    return "DBFilesClient\\PVPDifficulty.dbc";
}

bool PVPDifficultyRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MapID, sizeof(this->m_MapID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_RangeIndex, sizeof(this->m_RangeIndex), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MinLevel, sizeof(this->m_MinLevel), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MaxLevel, sizeof(this->m_MaxLevel), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Difficulty, sizeof(this->m_Difficulty), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}