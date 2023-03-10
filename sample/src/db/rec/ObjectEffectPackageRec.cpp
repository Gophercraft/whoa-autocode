// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/ObjectEffectPackageRec.hpp"
#include "util/SFile.hpp"

const char* ObjectEffectPackageRec::GetFilename() {
    return "DBFilesClient\\ObjectEffectPackage.dbc";
}

uint32_t ObjectEffectPackageRec::GetNumColumns() {
    return 2;
}

uint32_t ObjectEffectPackageRec::GetRowSize() {
    return 8;
}

bool ObjectEffectPackageRec::NeedIDAssigned() {
    return false;
}

int32_t ObjectEffectPackageRec::GetID() {
    return this->m_ID;
}

void ObjectEffectPackageRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool ObjectEffectPackageRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t nameOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &nameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_name = &stringBuffer[nameOfs];
    } else {
        this->m_name = "";
    }

    return true;
}
