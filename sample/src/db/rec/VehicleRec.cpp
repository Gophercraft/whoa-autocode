// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/VehicleRec.hpp"
#include "util/SFile.hpp"

const char* VehicleRec::GetFilename() {
    return "DBFilesClient\\Vehicle.dbc";
}

uint32_t VehicleRec::GetNumColumns() {
    return 40;
}

uint32_t VehicleRec::GetRowSize() {
    return 160;
}

bool VehicleRec::NeedIDAssigned() {
    return false;
}

int32_t VehicleRec::GetID() {
    return this->m_ID;
}

void VehicleRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool VehicleRec::Read(SFile* f, const char* stringBuffer) {
    uint32_t msslTrgtArcTextureOfs;
    uint32_t msslTrgtImpactTextureOfs;
    uint32_t msslTrgtImpactModelOfs[2];

    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_flags, sizeof(this->m_flags), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_turnSpeed, sizeof(this->m_turnSpeed), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_pitchSpeed, sizeof(this->m_pitchSpeed), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_pitchMin, sizeof(this->m_pitchMin), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_pitchMax, sizeof(this->m_pitchMax), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[0], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[1], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[2], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[3], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[4], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[5], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[6], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_seatID[7], sizeof(m_seatID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_mouseLookOffsetPitch, sizeof(this->m_mouseLookOffsetPitch), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_cameraFadeDistScalarMin, sizeof(this->m_cameraFadeDistScalarMin), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_cameraFadeDistScalarMax, sizeof(this->m_cameraFadeDistScalarMax), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_cameraPitchOffset, sizeof(this->m_cameraPitchOffset), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_facingLimitRight, sizeof(this->m_facingLimitRight), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_facingLimitLeft, sizeof(this->m_facingLimitLeft), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtTurnLingering, sizeof(this->m_msslTrgtTurnLingering), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtPitchLingering, sizeof(this->m_msslTrgtPitchLingering), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtMouseLingering, sizeof(this->m_msslTrgtMouseLingering), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtEndOpacity, sizeof(this->m_msslTrgtEndOpacity), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtArcSpeed, sizeof(this->m_msslTrgtArcSpeed), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtArcRepeat, sizeof(this->m_msslTrgtArcRepeat), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtArcWidth, sizeof(this->m_msslTrgtArcWidth), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtImpactRadius[0], sizeof(m_msslTrgtImpactRadius[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtImpactRadius[1], sizeof(m_msslTrgtImpactRadius[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &msslTrgtArcTextureOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &msslTrgtImpactTextureOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &msslTrgtImpactModelOfs[0], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &msslTrgtImpactModelOfs[1], sizeof(uint32_t), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_cameraYawOffset, sizeof(this->m_cameraYawOffset), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_uiLocomotionType, sizeof(this->m_uiLocomotionType), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_msslTrgtImpactTexRadius, sizeof(this->m_msslTrgtImpactTexRadius), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_vehicleUiindicatorID, sizeof(this->m_vehicleUiindicatorID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_powerDisplayID[0], sizeof(m_powerDisplayID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_powerDisplayID[1], sizeof(m_powerDisplayID[0]), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_powerDisplayID[2], sizeof(m_powerDisplayID[0]), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    if (stringBuffer) {
        this->m_msslTrgtArcTexture = &stringBuffer[msslTrgtArcTextureOfs];
        this->m_msslTrgtImpactTexture = &stringBuffer[msslTrgtImpactTextureOfs];
        this->m_msslTrgtImpactModel[0] = &stringBuffer[msslTrgtImpactModelOfs[0]];
        this->m_msslTrgtImpactModel[1] = &stringBuffer[msslTrgtImpactModelOfs[1]];
    } else {
        this->m_msslTrgtArcTexture = "";
        this->m_msslTrgtImpactTexture = "";
        this->m_msslTrgtImpactModel[0] = "";
        this->m_msslTrgtImpactModel[1] = "";
    }

    return true;
}
