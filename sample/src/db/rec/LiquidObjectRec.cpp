// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/LiquidObjectRec.hpp"

const char* LiquidObjectRec::GetFilename() {
    return "DBFilesClient\\LiquidObject.dbc";
}

bool LiquidObjectRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FlowDirection, sizeof(this->m_FlowDirection), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FlowSpeed, sizeof(this->m_FlowSpeed), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_LiquidTypeID, sizeof(this->m_LiquidTypeID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Fishable, sizeof(this->m_Fishable), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Reflection, sizeof(this->m_Reflection), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}