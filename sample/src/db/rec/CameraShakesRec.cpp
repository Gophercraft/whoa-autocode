// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/CameraShakesRec.hpp"

const char* CameraShakesRec::GetFilename() {
    return "DBFilesClient\\CameraShakes.dbc";
}

bool CameraShakesRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ShakeType, sizeof(this->m_ShakeType), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Direction, sizeof(this->m_Direction), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Amplitude, sizeof(this->m_Amplitude), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Frequency, sizeof(this->m_Frequency), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Duration, sizeof(this->m_Duration), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Phase, sizeof(this->m_Phase), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Coefficient, sizeof(this->m_Coefficient), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}