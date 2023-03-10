// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/ObjectEffectPackageElemRec.hpp"
#include "util/SFile.hpp"

const char* ObjectEffectPackageElemRec::GetFilename() {
    return "DBFilesClient\\ObjectEffectPackageElem.dbc";
}

uint32_t ObjectEffectPackageElemRec::GetNumColumns() {
    return 4;
}

uint32_t ObjectEffectPackageElemRec::GetRowSize() {
    return 16;
}

bool ObjectEffectPackageElemRec::NeedIDAssigned() {
    return false;
}

int32_t ObjectEffectPackageElemRec::GetID() {
    return this->m_ID;
}

void ObjectEffectPackageElemRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool ObjectEffectPackageElemRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_objectEffectPackageID, sizeof(this->m_objectEffectPackageID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_objectEffectGroupID, sizeof(this->m_objectEffectGroupID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_stateType, sizeof(this->m_stateType), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
