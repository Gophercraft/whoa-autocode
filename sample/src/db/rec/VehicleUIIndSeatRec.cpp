// DO NOT EDIT: generated by whoa-autocode
#include "db/rec/VehicleUIIndSeatRec.hpp"
#include "util/SFile.hpp"

const char* VehicleUIIndSeatRec::GetFilename() {
    return "DBFilesClient\\VehicleUIIndSeat.dbc";
}

uint32_t VehicleUIIndSeatRec::GetNumColumns() {
    return 5;
}

uint32_t VehicleUIIndSeatRec::GetRowSize() {
    return 20;
}

bool VehicleUIIndSeatRec::NeedIDAssigned() {
    return false;
}

int32_t VehicleUIIndSeatRec::GetID() {
    return this->m_ID;
}

void VehicleUIIndSeatRec::SetID(int32_t id) {
    this->m_ID = id;
}

bool VehicleUIIndSeatRec::Read(SFile* f, const char* stringBuffer) {
    if (
        !SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_vehicleUiindicatorID, sizeof(this->m_vehicleUiindicatorID), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_virtualSeatIndex, sizeof(this->m_virtualSeatIndex), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_xpos, sizeof(this->m_xpos), nullptr, nullptr, nullptr)
        || !SFile::Read(f, &this->m_ypos, sizeof(this->m_ypos), nullptr, nullptr, nullptr)
    ) {
        return false;
    }

    return true;
}
