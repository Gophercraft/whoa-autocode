// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/LiquidTypeRec.hpp"

const char* LiquidTypeRec::GetFilename() {
    return "DBFilesClient\\LiquidType.dbc";
}

bool LiquidTypeRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t NameOfs;
    uint32_t TextureOfs[6];

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &NameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Flags, sizeof(this->m_Flags), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundBank, sizeof(this->m_SoundBank), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundID, sizeof(this->m_SoundID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SpellID, sizeof(this->m_SpellID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MaxDarkenDepth, sizeof(this->m_MaxDarkenDepth), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FogDarkenIntensity, sizeof(this->m_FogDarkenIntensity), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_AmbDarkenIntensity, sizeof(this->m_AmbDarkenIntensity), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_DirDarkenIntensity, sizeof(this->m_DirDarkenIntensity), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_LightID, sizeof(this->m_LightID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ParticleScale, sizeof(this->m_ParticleScale), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ParticleMovement, sizeof(this->m_ParticleMovement), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ParticleTexSlots, sizeof(this->m_ParticleTexSlots), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MaterialID, sizeof(this->m_MaterialID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &TextureOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &TextureOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &TextureOfs[2], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &TextureOfs[3], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &TextureOfs[4], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &TextureOfs[5], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Color[0], sizeof(m_Color[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Color[1], sizeof(m_Color[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[0], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[1], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[2], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[3], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[4], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[5], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[6], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[7], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[8], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[9], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[10], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[11], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[12], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[13], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[14], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[15], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[16], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Float[17], sizeof(m_Float[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Int[0], sizeof(m_Int[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Int[1], sizeof(m_Int[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Int[2], sizeof(m_Int[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Int[3], sizeof(m_Int[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_Name = &stringBuffer[NameOfs];
        this->m_Texture[0] = &stringBuffer[TextureOfs[0]];
        this->m_Texture[1] = &stringBuffer[TextureOfs[1]];
        this->m_Texture[2] = &stringBuffer[TextureOfs[2]];
        this->m_Texture[3] = &stringBuffer[TextureOfs[3]];
        this->m_Texture[4] = &stringBuffer[TextureOfs[4]];
        this->m_Texture[5] = &stringBuffer[TextureOfs[5]];
    } else {
        this->m_Name = "";
        this->m_Texture[0] = "";
        this->m_Texture[1] = "";
        this->m_Texture[2] = "";
        this->m_Texture[3] = "";
        this->m_Texture[4] = "";
        this->m_Texture[5] = "";
    }

    return true;
}