// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_VIDEOHARDWARE_REC_HPP
#define DB_VIDEOHARDWARE_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct VideoHardwareRec {
	static constexpr uint32_t columnCount = 23;
	static constexpr uint32_t rowSize = 92;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_VendorID;
	int32_t m_DeviceID;
	int32_t m_FarclipIdx;
	int32_t m_TerrainLODDistIdx;
	int32_t m_TerrainShadowLOD;
	int32_t m_DetailDoodadDensityIdx;
	int32_t m_DetailDoodadAlpha;
	int32_t m_AnimatingDoodadIdx;
	int32_t m_Trilinear;
	int32_t m_NumLights;
	int32_t m_Specularity;
	int32_t m_WaterLODIdx;
	int32_t m_ParticleDensityIdx;
	int32_t m_UnitDrawDistIdx;
	int32_t m_SmallCullDistIdx;
	int32_t m_ResolutionIdx;
	int32_t m_BaseMipLevel;
	const char* m_OglOverrides;
	const char* m_D3dOverrides;
	int32_t m_FixLag;
	int32_t m_Multisample;
	int32_t m_Atlasdisable;

	static const char* GetFilename() {
		return "DBFilesClient\\VideoHardware.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t OglOverridesOfs;
		uint32_t D3dOverridesOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_VendorID, sizeof(this->m_VendorID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DeviceID, sizeof(this->m_DeviceID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_FarclipIdx, sizeof(this->m_FarclipIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_TerrainLODDistIdx, sizeof(this->m_TerrainLODDistIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_TerrainShadowLOD, sizeof(this->m_TerrainShadowLOD), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DetailDoodadDensityIdx, sizeof(this->m_DetailDoodadDensityIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_DetailDoodadAlpha, sizeof(this->m_DetailDoodadAlpha), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_AnimatingDoodadIdx, sizeof(this->m_AnimatingDoodadIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Trilinear, sizeof(this->m_Trilinear), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_NumLights, sizeof(this->m_NumLights), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Specularity, sizeof(this->m_Specularity), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_WaterLODIdx, sizeof(this->m_WaterLODIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ParticleDensityIdx, sizeof(this->m_ParticleDensityIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_UnitDrawDistIdx, sizeof(this->m_UnitDrawDistIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_SmallCullDistIdx, sizeof(this->m_SmallCullDistIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ResolutionIdx, sizeof(this->m_ResolutionIdx), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_BaseMipLevel, sizeof(this->m_BaseMipLevel), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &OglOverridesOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &D3dOverridesOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_FixLag, sizeof(this->m_FixLag), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Multisample, sizeof(this->m_Multisample), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Atlasdisable, sizeof(this->m_Atlasdisable), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		if (stringBuffer) {
			this->m_OglOverrides = &stringBuffer[OglOverridesOfs];
			this->m_D3dOverrides = &stringBuffer[D3dOverridesOfs];
		} else {
			this->m_OglOverrides = "";
			this->m_D3dOverrides = "";
		}

		return true;
	}
};

#endif