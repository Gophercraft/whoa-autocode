// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/AnimKitBoneSetRec.hpp"

const char* AnimKitBoneSetRec::GetFilename() {
    return "DBFilesClient\\AnimKitBoneSet.dbc";
}

bool AnimKitBoneSetRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t NameOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &NameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_BoneDataID, sizeof(this->m_BoneDataID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ParentAnimKitBoneSetID, sizeof(this->m_ParentAnimKitBoneSetID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ExtraBoneCount, sizeof(this->m_ExtraBoneCount), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_AltAnimKitBoneSetID, sizeof(this->m_AltAnimKitBoneSetID), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_Name = &stringBuffer[NameOfs];
    } else {
        this->m_Name = "";
    }

    return true;
}