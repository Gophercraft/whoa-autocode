// DO NOT EDIT: generated by whoa-autocode
#ifndef DB_LIGHTINTBAND_REC_HPP
#define DB_LIGHTINTBAND_REC_HPP

#include "util/SFile.hpp"
#include <cstdint>

struct LightIntBandRec {
	static constexpr uint32_t columnCount = 34;
	static constexpr uint32_t rowSize = 136;
	static constexpr bool indexIsID = false;

	int32_t m_ID;
	int32_t m_Num;
	int32_t m_Time[16];
	int32_t m_Data[16];

	static const char* GetFilename() {
		return "DBFilesClient\\LightIntBand.dbc";
	}

	bool Read(SFile* f, const char* stringBuffer) {
		if (
			!SFile::Read(f, &this->m_ID, sizeof(this->m_ID), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Num, sizeof(this->m_Num), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[0], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[1], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[2], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[3], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[4], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[5], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[6], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[7], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[8], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[9], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[10], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[11], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[12], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[13], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[14], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Time[15], sizeof(m_Time[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[0], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[1], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[2], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[3], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[4], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[5], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[6], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[7], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[8], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[9], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[10], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[11], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[12], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[13], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[14], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
			|| !SFile::Read(f, &this->m_Data[15], sizeof(m_Data[0]), nullptr, nullptr, nullptr)
		) {
			return false;
		}

		return true;
	}
};

#endif