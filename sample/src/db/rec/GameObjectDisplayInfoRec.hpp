// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_GAMEOBJECTDISPLAYINFO_REC_HPP
#define DB_GAMEOBJECTDISPLAYINFO_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct GameObjectDisplayInfoRec {
	static constexpr uint32_t columnCount = 19;
	static constexpr uint32_t rowSize = 76;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	const char* m_ModelName;
	int32_t m_Sound[10];
	float m_GeoBoxMin[3];
	float m_GeoBoxMax[3];
	int32_t m_ObjectEffectPackageID;

	static const char* GetFilename() {
		return "DBFilesClient\\GameObjectDisplayInfo.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		uint32_t ModelNameOfs;

		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &ModelNameOfs, sizeof(uint32_t), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[0], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[1], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[2], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[3], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[4], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[5], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[6], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[7], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[8], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Sound[9], sizeof(m_Sound[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GeoBoxMin[0], sizeof(m_GeoBoxMin[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GeoBoxMin[1], sizeof(m_GeoBoxMin[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GeoBoxMin[2], sizeof(m_GeoBoxMin[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GeoBoxMax[0], sizeof(m_GeoBoxMax[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GeoBoxMax[1], sizeof(m_GeoBoxMax[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_GeoBoxMax[2], sizeof(m_GeoBoxMax[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_ObjectEffectPackageID, sizeof(this->m_ObjectEffectPackageID), nullptr, nullptr, nullptr)
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
};

#endif