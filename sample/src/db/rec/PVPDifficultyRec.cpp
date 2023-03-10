// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/PVPDifficultyRec.hpp"
#include "util/SFile.hpp"

const char* PVPDifficultyRec::GetFilename() {
    return "DBFilesClient\\PVPDifficulty.dbc";
}

uint32_t PVPDifficultyRec::GetNumColumns() {
    return 6;
}

uint32_t PVPDifficultyRec::GetRowSize() {
    return 24;
}

bool PVPDifficultyRec::NeedIDAssigned() {
    return false;
}

int32_t PVPDifficultyRec::GetID() {
    return this->m_ID;
}

void PVPDifficultyRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool PVPDifficultyRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_mapID, sizeof(this->m_mapID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_rangeIndex, sizeof(this->m_rangeIndex), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_minLevel, sizeof(this->m_minLevel), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_maxLevel, sizeof(this->m_maxLevel), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty, sizeof(this->m_difficulty), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
