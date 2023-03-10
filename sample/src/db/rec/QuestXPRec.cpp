// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/QuestXPRec.hpp"
#include "util/SFile.hpp"

const char* QuestXPRec::GetFilename() {
    return "DBFilesClient\\QuestXP.dbc";
}

uint32_t QuestXPRec::GetNumColumns() {
    return 11;
}

uint32_t QuestXPRec::GetRowSize() {
    return 44;
}

bool QuestXPRec::NeedIDAssigned() {
    return false;
}

int32_t QuestXPRec::GetID() {
    return this->m_ID;
}

void QuestXPRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool QuestXPRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[0], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[1], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[2], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[3], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[4], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[5], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[6], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[7], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[8], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_difficulty[9], sizeof(m_difficulty[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
