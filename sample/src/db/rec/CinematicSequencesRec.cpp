// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/CinematicSequencesRec.hpp"
#include "util/SFile.hpp"

const char* CinematicSequencesRec::GetFilename() {
    return "DBFilesClient\\CinematicSequences.dbc";
}

uint32_t CinematicSequencesRec::GetNumColumns() {
    return 10;
}

uint32_t CinematicSequencesRec::GetRowSize() {
    return 40;
}

bool CinematicSequencesRec::NeedIDAssigned() {
    return false;
}

int32_t CinematicSequencesRec::GetID() {
    return this->m_ID;
}

void CinematicSequencesRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool CinematicSequencesRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_soundID, sizeof(this->m_soundID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[0], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[1], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[2], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[3], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[4], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[5], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[6], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_camera[7], sizeof(m_camera[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
