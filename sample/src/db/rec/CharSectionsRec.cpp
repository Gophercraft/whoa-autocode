// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/CharSectionsRec.hpp"
#include "util/SFile.hpp"

const char* CharSectionsRec::GetFilename() {
    return "DBFilesClient\\CharSections.dbc";
}

uint32_t CharSectionsRec::GetNumColumns() {
    return 10;
}

uint32_t CharSectionsRec::GetRowSize() {
    return 40;
}

bool CharSectionsRec::NeedIDAssigned() {
    return false;
}

int32_t CharSectionsRec::GetID() {
    return this->m_ID;
}

void CharSectionsRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool CharSectionsRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t textureNameOfs[3];

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_raceID, sizeof(this->m_raceID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_sexID, sizeof(this->m_sexID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_baseSection, sizeof(this->m_baseSection), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &textureNameOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &textureNameOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &textureNameOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_flags, sizeof(this->m_flags), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_variationIndex, sizeof(this->m_variationIndex), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_colorIndex, sizeof(this->m_colorIndex), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_textureName[0] = &stringBuffer[textureNameOfs[0]];
        this->m_textureName[1] = &stringBuffer[textureNameOfs[1]];
        this->m_textureName[2] = &stringBuffer[textureNameOfs[2]];
    } else {
        this->m_textureName[0] = "";
        this->m_textureName[1] = "";
        this->m_textureName[2] = "";
    }

    return true;
}
