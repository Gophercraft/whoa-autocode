// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/CreatureModelDataRec.hpp"

const char* CreatureModelDataRec::GetFilename() {
    return "DBFilesClient\\CreatureModelData.dbc";
}

bool CreatureModelDataRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t ModelNameOfs;

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_Flags, sizeof(this->m_Flags), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &ModelNameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SizeClass, sizeof(this->m_SizeClass), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ModelScale, sizeof(this->m_ModelScale), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_BloodID, sizeof(this->m_BloodID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FootprintTextureID, sizeof(this->m_FootprintTextureID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FootprintTextureLength, sizeof(this->m_FootprintTextureLength), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FootprintTextureWidth, sizeof(this->m_FootprintTextureWidth), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FootprintParticleScale, sizeof(this->m_FootprintParticleScale), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FoleyMaterialID, sizeof(this->m_FoleyMaterialID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_FootstepShakeSize, sizeof(this->m_FootstepShakeSize), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_DeathThudShakeSize, sizeof(this->m_DeathThudShakeSize), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_SoundID, sizeof(this->m_SoundID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_CollisionWidth, sizeof(this->m_CollisionWidth), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_CollisionHeight, sizeof(this->m_CollisionHeight), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MountHeight, sizeof(this->m_MountHeight), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_GeoBoxMinX, sizeof(this->m_GeoBoxMinX), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_GeoBoxMinY, sizeof(this->m_GeoBoxMinY), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_GeoBoxMinZ, sizeof(this->m_GeoBoxMinZ), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_GeoBoxMaxX, sizeof(this->m_GeoBoxMaxX), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_GeoBoxMaxY, sizeof(this->m_GeoBoxMaxY), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_GeoBoxMaxZ, sizeof(this->m_GeoBoxMaxZ), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_WorldEffectScale, sizeof(this->m_WorldEffectScale), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_AttachedEffectScale, sizeof(this->m_AttachedEffectScale), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MissileCollisionRadius, sizeof(this->m_MissileCollisionRadius), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MissileCollisionPush, sizeof(this->m_MissileCollisionPush), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_MissileCollisionRaise, sizeof(this->m_MissileCollisionRaise), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_ModelName = &stringBuffer[ModelNameOfs];
    } else {
        this->m_ModelName = "";
    }

    return true;
}