// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/UnitBloodLevelsRec.hpp"

const char* UnitBloodLevelsRec::GetFilename() {
    return "DBFilesClient\\UnitBloodLevels.dbc";
}

bool UnitBloodLevelsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Violencelevel[0], sizeof(m_Violencelevel[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Violencelevel[1], sizeof(m_Violencelevel[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Violencelevel[2], sizeof(m_Violencelevel[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}