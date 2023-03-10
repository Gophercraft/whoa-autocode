// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/SpellMissileMotionRec.hpp"
#include "util/SFile.hpp"

const char* SpellMissileMotionRec::GetFilename() {
    return "DBFilesClient\\SpellMissileMotion.dbc";
}

uint32_t SpellMissileMotionRec::GetNumColumns() {
    return 5;
}

uint32_t SpellMissileMotionRec::GetRowSize() {
    return 20;
}

bool SpellMissileMotionRec::NeedIDAssigned() {
    return false;
}

int32_t SpellMissileMotionRec::GetID() {
    return this->m_ID;
}

void SpellMissileMotionRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool SpellMissileMotionRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t nameOfs;
    uint32_t scriptBodyOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &scriptBodyOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_flags, sizeof(this->m_flags), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_missileCount, sizeof(this->m_missileCount), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_name = &stringBuffer[nameOfs];
        this->m_scriptBody = &stringBuffer[scriptBodyOfs];
    } else {
        this->m_name = "";
        this->m_scriptBody = "";
    }

    return true;
}
