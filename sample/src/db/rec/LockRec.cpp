// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/LockRec.hpp"

const char* LockRec::GetFilename() {
    return "DBFilesClient\\Lock.dbc";
}

bool LockRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[0], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[1], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[2], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[3], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[4], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[5], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[6], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Type[7], sizeof(m_Type[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[0], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[1], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[2], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[3], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[4], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[5], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[6], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Index[7], sizeof(m_Index[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[0], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[1], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[2], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[3], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[4], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[5], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[6], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Skill[7], sizeof(m_Skill[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[0], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[1], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[2], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[3], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[4], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[5], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[6], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Action[7], sizeof(m_Action[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}