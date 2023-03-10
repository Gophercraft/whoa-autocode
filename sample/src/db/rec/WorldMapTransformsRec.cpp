// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/WorldMapTransformsRec.hpp"
#include "util/SFile.hpp"

const char* WorldMapTransformsRec::GetFilename() {
    return "DBFilesClient\\WorldMapTransforms.dbc";
}

uint32_t WorldMapTransformsRec::GetNumColumns() {
    return 10;
}

uint32_t WorldMapTransformsRec::GetRowSize() {
    return 40;
}

bool WorldMapTransformsRec::NeedIDAssigned() {
    return false;
}

int32_t WorldMapTransformsRec::GetID() {
    return this->m_ID;
}

void WorldMapTransformsRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool WorldMapTransformsRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_mapID, sizeof(this->m_mapID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_regionMin[0], sizeof(m_regionMin[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_regionMin[1], sizeof(m_regionMin[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_regionMax[0], sizeof(m_regionMax[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_regionMax[1], sizeof(m_regionMax[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_newMapID, sizeof(this->m_newMapID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_regionOffset[0], sizeof(m_regionOffset[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_regionOffset[1], sizeof(m_regionOffset[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_newDungeonMapID, sizeof(this->m_newDungeonMapID), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
