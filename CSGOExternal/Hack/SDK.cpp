#include "stdafx.h"
#include <Hack\Hack.h>
namespace Game {
	CWeapon * CWeapon::GetWeapon (int iIndex)
	{
		return CGame::GetInstance ().GetProcess ().Read<CWeapon*> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwEntityList") + (0x10 * iIndex));
	}

	CPlayer * CPlayer::GetPlayer (int iIndex)
	{
		return CGame::GetInstance ().GetProcess ().Read<CPlayer*> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwEntityList") + (0x10 * iIndex));
	}

	CPlayer * CPlayer::GetLocalPlayer ()
	{
		return CGame::GetInstance ().GetProcess ().Read<CPlayer*> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwLocalPlayer"));
	}

	int CWeapon::GetIndex ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + 0x64) - 1;
	}

	int CWeapon::GetClip ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iClip1"));
	}

	WeaponId CWeapon::GetID ()
	{
		return CGame::GetInstance ().GetProcess ().Read<WeaponId> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iWeaponId"));
	}

	float CWeapon::GetNextPrimaryAttack ()
	{
		return CGame::GetInstance ().GetProcess ().Read<float> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_flNextPrimaryAttack"));
	}

	bool CWeapon::InReload ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_bInReload"));
	}

	bool CWeapon::IsReloaded ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_bReloadVisuallyComplete"));
	}

	int CPlayer::GetIndex ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + 0x64) - 1;
	}

	int CPlayer::GetFlags ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_fFlags"));
	}

	Team CPlayer::GetTeam ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Team> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iTeamNum"));
	}

	int CPlayer::GetHealth ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iHealth"));
	}

	int CPlayer::GetArmor ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_ArmorValue"));
	}

	Util::Vector3 CPlayer::GetBonePosition (Bone_e eBone)
	{
		DWORD dwBoneMatrix = CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_dwBoneMatrix"));
		return Util::Vector3 (
			CGame::GetInstance ().GetProcess ().Read<float> (dwBoneMatrix + 0x30 * eBone + 0x0C),
			CGame::GetInstance ().GetProcess ().Read<float> (dwBoneMatrix + 0x30 * eBone + 0x1C),
			CGame::GetInstance ().GetProcess ().Read<float> (dwBoneMatrix + 0x30 * eBone + 0x2C)
		);
	}

	Util::Vector3 CPlayer::GetPosition ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector3> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_vecOrigin"));
	}

	Util::Vector3 CPlayer::GetVelocity ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector3> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_vecVelocity"));
	}

	Util::Vector3 CPlayer::GetViewOffset ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector3> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_vecViewOffset"));
	}

	Util::Vector3 CPlayer::GetEyePosition ()
	{
		return this->GetPosition () + this->GetViewOffset ();
	}

	Util::Vector3 CPlayer::GetAimPunch ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector3> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_Local") + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_aimPunchAngle"));
	}

	Util::Vector3 CPlayer::GetVisualPunch ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector3> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_Local") + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_viewPunchAngle"));
	}

	void CPlayer::SetVisualPunch (Util::Vector3 vPunch)
	{
		CGame::GetInstance ().GetProcess ().Write<Util::Vector3> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_Local") + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_viewPunchAngle"), vPunch);
	}

	int CPlayer::GetTick ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_nTickBase")) + (int)CGlobalVars::GetInstance ()->GetIntervalPerTick ();
	}

	int CPlayer::GetGlowIndex ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iGlowIndex"));
	}

	int CPlayer::GetShotsFired ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iShotsFired"));
	}

	int CPlayer::GetInCrosshair ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_iCrosshairId")) - 1;
	}

	bool CPlayer::IsDormant ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> ((DWORD)this + 0xE9);
	}

	bool CPlayer::IsDead ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_lifeState"));
	}

	bool CPlayer::IsSpotted ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_bSpotted"));
	}

	void CPlayer::Spotted (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<bool> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_bSpotted"), bState);
	}

	float CPlayer::GetFlashDuration ()
	{
		return CGame::GetInstance ().GetProcess ().Read<float> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_flFlashDuration"));
	}

	void CPlayer::SetFlashDuration (float flFlashDuration)
	{
		CGame::GetInstance ().GetProcess ().Write<float> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_flFlashDuration"), flFlashDuration);
	}

	bool CPlayer::CanAttack ()
	{
		if (this->IsDead () || this->IsDormant ())
			return false;

		CWeapon* pWeapon = this->GetCurrentWeapon ();

		if (pWeapon->GetClip () <= 0)
			return false;

		if (std::floor (pWeapon->GetNextPrimaryAttack ()) - this->GetTick () > 0)
			return false;

		return true;
	}

	CWeapon * CPlayer::GetCurrentWeapon ()
	{
		DWORD dwBaseWeaponIndex = CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this + Dumper::CNetVarDumper::GetInstance ().FindSignature ("m_hActiveWeapon"));
		dwBaseWeaponIndex &= 0xFFF;
		dwBaseWeaponIndex -= 1;
		return CGame::GetInstance ().GetProcess ().Read<CWeapon*> ((CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwEntityList") + dwBaseWeaponIndex * 0x10));
	}

	Util::Vector3 CEngine::GetViewAngle ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector3> (CGame::GetInstance ().GetProcess ().Read<DWORD> (CGame::GetInstance ().GetModule ("engine.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwClientState")) + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwClientState_ViewAngles"));
	}

	void CEngine::SetViewAngle (Util::Vector3 vAngle)
	{
		CEngine::AngleNormalizeClamp (vAngle);
		CGame::GetInstance ().GetProcess ().Write<Util::Vector3> (CGame::GetInstance ().GetProcess ().Read<DWORD> (CGame::GetInstance ().GetModule ("engine.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwClientState")) + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwClientState_ViewAngles"), vAngle);
	}

	void CEngine::Attack ()
	{
		if (CEngine::GetAttack ()) {
			return;
		}
		CEngine::SetAttack (true);
		std::this_thread::sleep_for (std::chrono::milliseconds (1));
		CEngine::SetAttack (false);
	}

	void CEngine::Attack2 ()
	{
		if (CEngine::GetAttack2 ()) {
			return;
		}
		CEngine::SetAttack2 (true);
		std::this_thread::sleep_for (std::chrono::milliseconds (1));
		CEngine::SetAttack2 (false);
	}

	void CEngine::Jump ()
	{
		if (CEngine::GetJump ()) {
			return;
		}
		CEngine::SetJump (true);
		std::this_thread::sleep_for (std::chrono::milliseconds (1));
		CEngine::SetJump (false);
	}

	bool CEngine::GetJump ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwForceJump")) == 5;
	}

	void CEngine::SetJump (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<int> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwForceJump"), bState ? 5 : 4);
	}

	bool CEngine::GetAttack ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwForceAttack")) == 5;
	}

	void CEngine::SetAttack (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<int> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwForceAttack"), bState ? 5 : 4);
	}

	bool CEngine::GetAttack2 ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwForceAttack2")) == 5;
	}

	void CEngine::SetAttack2 (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<int> (CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwForceAttack2"), bState ? 5 : 4);
	}

	bool CEngine::GetSendPacket ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> (CGame::GetInstance ().GetModule ("engine.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwbSendPackets"));
	}

	void CEngine::SetSendPacket (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<bool> (CGame::GetInstance ().GetModule ("engine.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwbSendPackets"), bState);
	}

	bool CEngine::IsAngleNAN (Util::Vector3 vAngle)
	{
		return (
			vAngle.m_flXPos > 89.f || 
			vAngle.m_flXPos < -89.f || 
			vAngle.m_flYPos > 180.f || 
			vAngle.m_flYPos < -180.f || 
			vAngle.m_flZPos != 0.f ||
			(!std::isfinite (vAngle.m_flXPos) || std::isnan (vAngle.m_flXPos) ||
			(!std::isfinite (vAngle.m_flYPos) || std::isnan (vAngle.m_flYPos))));
	}

	void CEngine::AngleNormalizeClamp (Util::Vector3 & vAngle)
	{
		vAngle.m_flXPos = Util::clamp (std::remainder (vAngle.m_flXPos, 180.f), -89.f, 89.f);
		vAngle.m_flYPos = Util::clamp (std::remainder (vAngle.m_flYPos, 360.f), -180.f, 180.f);
		vAngle.m_flZPos = 0.f;
	}

	Util::Vector3 CEngine::CalculatePunchReduction (Util::Vector2 vPitch, Util::Vector2 vYaw)
	{
		return Util::Vector3 (CEngine::Random<float> (vPitch), CEngine::Random<float> (vYaw), 0.f);
	}

	Util::Vector3 CEngine::CalculateSmoothAngle (Util::Vector3 vSrcAngle, Util::Vector3 vDstAngle, float smoothAmount)
	{
		smoothAmount = Util::clamp (smoothAmount, 0.f, 100.f);

		Util::Vector3 vSmoothAngle (0.f);
		vSmoothAngle = vSrcAngle + ((vDstAngle - vSrcAngle) * (Util::Vector3 (smoothAmount) / Util::Vector3 (100.f)));
		vSmoothAngle.m_flZPos = 0.f;

		CEngine::AngleNormalizeClamp (vSmoothAngle);

		return vSmoothAngle;
	}

	Util::Vector3 CEngine::CalculateAngle (Util::Vector3 vSrcPosition, Util::Vector3 vDstPosition)
	{
		Util::Vector3 vAimAngle = (vDstPosition - vSrcPosition).ToAngle ();
		CEngine::AngleNormalizeClamp (vAimAngle);
		return vAimAngle;
	}

	bool CEngine::IsInFOV (Util::Vector3 vSrcPosition, Util::Vector3 vDstPosition, float flInFOV, float & flFOV)
	{
		Util::Vector3 vAimAngle = Game::CEngine::CalculateAngle (vSrcPosition, vDstPosition);
		Util::Vector3 vViewAngle = Game::CEngine::GetViewAngle ();
		Util::Vector3 vDelta = vViewAngle - vAimAngle;

		Util::Vector3 vFOV = Util::Vector3 (sin (M_DEG2RAD (vDelta.m_flXPos)), sin (M_DEG2RAD (vDelta.m_flYPos)), 0) * Util::Vector3 (vSrcPosition.Distance (vDstPosition));

		flFOV = vFOV.Length ();

		if (std::isnan (flFOV))
		{
			flFOV = 360.f;
		}

		return flFOV < flInFOV;
	}

	bool CEngine::RayTrace (Util::Vector3 leftBottom, Util::Vector3 rightTop, float & fDistance)
	{
		auto pLocal = CPlayer::GetLocalPlayer();

		Util::Vector3 vEyePosition = pLocal->GetEyePosition();
		Util::Vector3 vAngle = CEngine::GetViewAngle();
		CEngine::AngleNormalizeClamp (vAngle);

		Util::Vector3 vDirection = vAngle.ToVector ();
		Util::Vector3 vDirectionInverse = (Util::Vector3 (1.f) / vDirection);

		if (vDirection.m_flXPos == 0.0f && (vEyePosition.m_flXPos < std::min (leftBottom.m_flXPos, rightTop.m_flXPos) || vEyePosition.m_flXPos > std::max (leftBottom.m_flXPos, rightTop.m_flXPos)))
			return false;

		if (vDirection.m_flYPos == 0.0f && (vEyePosition.m_flYPos < std::min (leftBottom.m_flYPos, rightTop.m_flYPos) || vEyePosition.m_flYPos > std::max (leftBottom.m_flYPos, rightTop.m_flYPos)))
			return false;

		if (vDirection.m_flZPos == 0.0f && (vEyePosition.m_flZPos < std::min (leftBottom.m_flZPos, rightTop.m_flZPos) || vEyePosition.m_flZPos > std::max (leftBottom.m_flZPos, rightTop.m_flZPos)))
			return false;

		float t1 = (leftBottom.m_flXPos - vEyePosition.m_flXPos) * vDirectionInverse.m_flXPos;
		float t2 = (rightTop.m_flXPos - vEyePosition.m_flXPos) * vDirectionInverse.m_flXPos;
		float t3 = (leftBottom.m_flYPos - vEyePosition.m_flYPos) * vDirectionInverse.m_flYPos;
		float t4 = (rightTop.m_flYPos - vEyePosition.m_flYPos) * vDirectionInverse.m_flYPos;
		float t5 = (leftBottom.m_flZPos - vEyePosition.m_flZPos) * vDirectionInverse.m_flZPos;
		float t6 = (rightTop.m_flZPos - vEyePosition.m_flZPos) * vDirectionInverse.m_flZPos;

		float tmin = std::max (std::max (std::min (t1, t2), std::min (t3, t4)), std::min (t5, t6));
		float tmax = std::min (std::min (std::max (t1, t2), std::max (t3, t4)), std::max (t5, t6));

		if (tmax < 0)
		{
			fDistance = tmax;
			return false;
		}

		if (tmin > tmax)
		{
			fDistance = tmax;
			return false;
		}
		fDistance = tmin;
		return true;
	}

	void CEngine::SetClanTag (const char * tag, const char * name)
	{
		unsigned char Shellcode[] =
			"\x51"					//push ecx
			"\x52"					//push edx
			"\xB9\x00\x00\x00\x00"	//mov ecx,00000000 { 0 }
			"\xBA\x00\x00\x00\x00"	//mov edx,00000000 { 0 }
			"\xE8\x00\x00\x00\x00"  //call 0
			"\x83\x04\x24\x0A"      //add dword ptr [esp],0A { 10 }
			"\x68\x00\x00\x00\x00"	//push engine.dll+9AC90
			"\xC3"					//ret
			"\x5A"					//pop edx
			"\x59"					//pop ecx
			"\xC3"					//ret
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" //reserve memory[0x10]
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00" //reserve memory[0x10]
			;

		static unsigned int SHELLCODE_SIZE = sizeof (Shellcode) - 0x21;
		unsigned int TAG_SIZE = (strlen (tag) > 15) ? 15 : strlen (tag);
		unsigned int NAME_SIZE = (strlen (name) > 15) ? 15 : strlen (name);
		unsigned int DATA_SIZE = TAG_SIZE + NAME_SIZE + 2;

		LPVOID pShellCodeAdress = VirtualAllocEx (
			CGame::GetInstance().GetProcess().GetProcessHandle(),
			0,
			SHELLCODE_SIZE + DATA_SIZE,
			MEM_COMMIT | MEM_RESERVE,
			PAGE_EXECUTE_READWRITE
		);

		DWORD tagAdress = (DWORD)pShellCodeAdress + SHELLCODE_SIZE;
		DWORD nameAdress = (DWORD)pShellCodeAdress + SHELLCODE_SIZE + TAG_SIZE + 1;
		DWORD fnSetClanAdress = CGame::GetInstance ().GetModule ("engine.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance().FindSignature("dwSetClanTag");

		memcpy (Shellcode + 0x3, &tagAdress, sizeof (DWORD));
		memcpy (Shellcode + 0x8, &nameAdress, sizeof (DWORD));
		memcpy (Shellcode + 0x16, &fnSetClanAdress, sizeof (DWORD));
		memcpy (Shellcode + SHELLCODE_SIZE, tag, TAG_SIZE);
		memcpy (Shellcode + SHELLCODE_SIZE + TAG_SIZE + 1, name, NAME_SIZE);

		WriteProcessMemory (CGame::GetInstance ().GetProcess ().GetProcessHandle (), pShellCodeAdress, Shellcode, SHELLCODE_SIZE + DATA_SIZE, 0);

		HANDLE hThread = CreateRemoteThread (CGame::GetInstance ().GetProcess ().GetProcessHandle (), NULL, NULL, (LPTHREAD_START_ROUTINE)pShellCodeAdress, NULL, NULL, NULL);
		WaitForSingleObject (hThread, INFINITE);
		VirtualFreeEx (CGame::GetInstance ().GetProcess ().GetProcessHandle (), pShellCodeAdress, 0, MEM_RELEASE);
	}

	int CBase::GetID ()
	{
		DWORD PlayerBaseVT = CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this + 0x8);
		if (PlayerBaseVT)
		{
			DWORD PlayerBaseFN = CGame::GetInstance ().GetProcess ().Read<DWORD> (PlayerBaseVT + 2 * 0x4);
			if (PlayerBaseFN)
			{
				DWORD PlayerBaseCLS = CGame::GetInstance ().GetProcess ().Read<DWORD> (PlayerBaseFN + 1);
				if (PlayerBaseCLS)
				{
					return CGame::GetInstance ().GetProcess ().Read<DWORD> (PlayerBaseCLS + 20);
				}
			}
		}
		return 0;
	}

	std::string CBase::GetName ()
	{
		DWORD PlayerBaseVT = CGame::GetInstance ().GetProcess ().Read<DWORD> ((DWORD)this + 0x8);
		if (PlayerBaseVT)
		{
			DWORD PlayerBaseFN = CGame::GetInstance ().GetProcess ().Read<DWORD> (PlayerBaseVT + 2 * 0x4);
			if (PlayerBaseFN)
			{
				DWORD PlayerBaseCLS = CGame::GetInstance ().GetProcess ().Read<DWORD> (PlayerBaseFN + 1);
				if (PlayerBaseCLS)
				{
					DWORD PlayerBaseCLSName = CGame::GetInstance ().GetProcess ().Read<DWORD> (PlayerBaseCLS + 8);
					if (PlayerBaseCLSName)
					{
						char szClassName[32] = "\0";
						for (int i = 0; i < 32; i++)
						{
							szClassName[i] = CGame::GetInstance ().GetProcess ().Read<char> (PlayerBaseCLSName + i * sizeof (char));
							if (!szClassName[i])
								break;
						}
						return std::string (szClassName);
					}
				}
			}
		}
		return "Unknown";
	}

	CGlobalVars* CGlobalVars::GetInstance ()
	{
		return (CGlobalVars*)(CGame::GetInstance ().GetModule ("engine.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwGlobalVars"));
	}

	int CGlobalVars::GetMaxClients ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + 0x18);
	}

	int CGlobalVars::GetTickCount ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + 0x1C);
	}

	float CGlobalVars::GetIntervalPerTick ()
	{
		return CGame::GetInstance ().GetProcess ().Read<float> ((DWORD)this + 0x20);
	}

	CGlowObjectManager * CGlowObjectManager::GetInstance ()
	{
		return (CGlowObjectManager*)(CGame::GetInstance ().GetModule ("client.dll").GetModuleBase () + Dumper::CSignatureDumper::GetInstance ().FindSignature ("dwGlowObjectManager"));
	}

	int CGlowObjectManager::GetGlowObjectCount ()
	{
		return CGame::GetInstance().GetProcess().Read<int>((DWORD)this + 0x4);
	}

	CGlowObject * CGlowObjectManager::GetGlowObject (int iIndex)
	{
		return (CGlowObject*)(CGame::GetInstance().GetProcess().Read<DWORD>((DWORD)this) + iIndex * 0x38);
	
	}
	CBase * CGlowObject::GetEntity ()
	{
		return CGame::GetInstance ().GetProcess ().Read<CBase*> ((DWORD)this + 0x0);
	}

	Util::Vector4 CGlowObject::GetColor ()
	{
		return CGame::GetInstance ().GetProcess ().Read<Util::Vector4> ((DWORD)this + 0x4);
	}

	void CGlowObject::SetColor (Util::Vector4 vColor)
	{
		CGame::GetInstance ().GetProcess ().Write<Util::Vector4> ((DWORD)this + 0x4, vColor);
	}

	bool CGlowObject::IsRenderWhenOccluded ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> ((DWORD)this + 0x24);
	}

	void CGlowObject::SetRenderWhenOccluded (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<bool> ((DWORD)this + 0x24, bState);
	}

	bool CGlowObject::IsRenderWhenUnoccluded ()
	{
		return CGame::GetInstance ().GetProcess ().Read<bool> ((DWORD)this + 0x25);
	}

	void CGlowObject::SetRenderWhenUnoccluded (bool bState)
	{
		CGame::GetInstance ().GetProcess ().Write<bool> ((DWORD)this + 0x25, bState);
	}

	int CGlowObject::GetGlowStyle ()
	{
		return CGame::GetInstance ().GetProcess ().Read<int> ((DWORD)this + 0x2C);
	}

	void CGlowObject::SetGlowStyle (int iStyle)
	{
		CGame::GetInstance ().GetProcess ().Write<int> ((DWORD)this + 0x2C, iStyle);
	}

	float CGlowObject::GetVelocity ()
	{
		return CGame::GetInstance ().GetProcess ().Read<float> ((DWORD)this + 0x18);
	}

	void CGlowObject::SetVelocity (float flVelocity)
	{
		CGame::GetInstance ().GetProcess ().Write<float> ((DWORD)this + 0x18, flVelocity);
	}

	CPlayerResource * CPlayerResource::GetInstance ()
	{
		return CGame::GetInstance().GetProcess().Read<CPlayerResource*>(CGame::GetInstance().GetModule("client.dll").GetModuleBase() + Dumper::CSignatureDumper::GetInstance().FindSignature("dwPlayerResource"));
	}

	CompetetiveTeammateColor CPlayerResource::GetCompetitiveTeammateColor (int iIndex)
	{
		return CGame::GetInstance().GetProcess().Read<CompetetiveTeammateColor>((DWORD)this + Dumper::CNetVarDumper::GetInstance().FindSignature("m_iCompTeammateColor") + (iIndex+1) * 0x4);
	}
}