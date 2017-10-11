#pragma once
#include "stdafx.h"

#include <Util\Vector2.h>
#include <Util\Vector3.h>
#include <Util\Vector4.h>
#include <Util\ColorUtil.h>

#define FL_ONGROUND (1 << 0)
#define FL_DUCKING (1 << 1)
#define FL_PARTIALGROUND (1 << 18)

namespace Game {
	const Util::Vector3 vBoundingBoxOffsets = Util::Vector3 (2.f);

	typedef enum CompetetiveTeammateColor_e
	{
		COMP_COLOR_UNKNOWN = -2,
		COMP_COLOR_GREY = -1,
		COMP_COLOR_YELLOW = 0,
		COMP_COLOR_PURPLE = 1,
		COMP_COLOR_GREEN = 2,
		COMP_COLOR_BLUE = 3,
		COMP_COLOR_ORANGE = 4,
		COMP_COLOR_MAX
	} CompetetiveTeammateColor;

	typedef enum SignOnState_e
	{
		SIGNONSTATE_NONE = 0,
		SIGNONSTATE_CHALLENGE = 1,
		SIGNONSTATE_CONNECTED = 2,
		SIGNONSTATE_NEW = 3,
		SIGNONSTATE_PRESPAWN = 4,
		SIGNONSTATE_SPAWN = 5,
		SIGNONSTATE_FULL = 6,
		SIGNONSTATE_CHANGELEVEL = 7,
	} SignOnState;

	typedef enum Team_e
	{
		NONE = 0,
		TEAM_SPECTATOR = 1,
		TEAM_TERRORISTS = 2,
		TEAM_COUNTER_TERRORISTS = 3
	} Team;

	typedef enum WeaponID_e
	{
		UNKNOWN,
		DEAGLE,
		ELITE,
		FIVESEVEN,
		GLOCK,
		P228,
		USP,
		AK47,
		AUG,
		AWP,
		FAMAS,
		G3SG1,
		GALIL,
		GALILAR,
		M249,
		M3,
		M4A1,
		MAC10,
		MP5NAVY,
		P90,
		SCOUT,
		SG550,
		SG552,
		TMP,
		UMP45,
		XM1014,
		BIZON,
		MAG7,
		NEGEV,
		SAWEDOFF,
		TEC9,
		TASER,
		HKP2000,
		MP7,
		MP9,
		NOVA,
		P250,
		SCAR17,
		SCAR20,
		SG556,
		SSG08,
		KNIFEGG,
		KNIFE,
		FLASHBANG,
		HEGRENADE,
		SMOKEGRENADE,
		MOLOTOV,
		DECOY,
		INCGRENADE,
		C4,
		MAX
	} WeaponId;

	typedef enum ClassID_e
	{
		CAI_BASENPC,
		CAK47,
		CBASEANIMATING,
		CBASEANIMATINGOVERLAY,
		CBASEATTRIBUTABLEITEM,
		CBASEBUTTON,
		CBASECOMBATCHARACTER,
		CBASECOMBATWEAPON,
		CBASECSGRENADE,
		CBASECSGRENADEPROJECTILE,
		CBASEDOOR,
		CBASEENTITY,
		CBASEFLEX,
		CBASEGRENADE,
		CBASEPARTICLEENTITY,
		CBASEPLAYER,
		CBASEPROPDOOR,
		CBASETEAMOBJECTIVERESOURCE,
		CBASETEMPENTITY,
		CBASETOGGLE,
		CBASETRIGGER,
		CBASEVIEWMODEL,
		CBASEVPHYSICSTRIGGER,
		CBASEWEAPONWORLDMODEL,
		CBEAM,
		CBEAMSPOTLIGHT,
		CBONEFOLLOWER,
		CBREAKABLEPROP,
		CBREAKABLESURFACE,
		CC4,
		CCASCADELIGHT,
		CCHICKEN,
		CCOLORCORRECTION,
		CCOLORCORRECTIONVOLUME,
		CCSGAMERULESPROXY,
		CCSPLAYER,
		CCSPLAYERRESOURCE,
		CCSRAGDOLL,
		CCSTEAM,
		CDEAGLE,
		CDECOYGRENADE,
		CDECOYPROJECTILE,
		CDYNAMICLIGHT,
		CDYNAMICPROP,
		CECONENTITY,
		CECONWEARABLE,
		CEMBERS,
		CENTITYDISSOLVE,
		CENTITYFLAME,
		CENTITYFREEZING,
		CENTITYPARTICLETRAIL,
		CENVAMBIENTLIGHT,
		CENVDETAILCONTROLLER,
		CENVDOFCONTROLLER,
		CENVPARTICLESCRIPT,
		CENVPROJECTEDTEXTURE,
		CENVQUADRATICBEAM,
		CENVSCREENEFFECT,
		CENVSCREENOVERLAY,
		CENVTONEMAPCONTROLLER,
		CENVWIND,
		CFEPLAYERDECAL,
		CFIRECRACKERBLAST,
		CFIRESMOKE,
		CFIRETRAIL,
		CFISH,
		CFLASHBANG,
		CFOGCONTROLLER,
		CFOOTSTEPCONTROL,
		CFUNC_DUST,
		CFUNC_LOD,
		CFUNCAREAPORTALWINDOW,
		CFUNCBRUSH,
		CFUNCCONVEYOR,
		CFUNCLADDER,
		CFUNCMONITOR,
		CFUNCMOVELINEAR,
		CFUNCOCCLUDER,
		CFUNCREFLECTIVEGLASS,
		CFUNCROTATING,
		CFUNCSMOKEVOLUME,
		CFUNCTRACKTRAIN,
		CGAMERULESPROXY,
		CHANDLETEST,
		CHEGRENADE,
		CHOSTAGE,
		CHOSTAGECARRIABLEPROP,
		CINCENDIARYGRENADE,
		CINFERNO,
		CINFOLADDERDISMOUNT,
		CINFOOVERLAYACCESSOR,
		CITEM_HEALTHSHOT,
		CKNIFE,
		CKNIFEGG,
		CLIGHTGLOW,
		CMATERIALMODIFYCONTROL,
		CMOLOTOVGRENADE,
		CMOLOTOVPROJECTILE,
		CMOVIEDISPLAY,
		CPARTICLEFIRE,
		CPARTICLEPERFORMANCEMONITOR,
		CPARTICLESYSTEM,
		CPHYSBOX,
		CPHYSBOXMULTIPLAYER,
		CPHYSICSPROP,
		CPHYSICSPROPMULTIPLAYER,
		CPHYSMAGNET,
		CPLANTEDC4,
		CPLASMA,
		CPLAYERRESOURCE,
		CPOINTCAMERA,
		CPOINTCOMMENTARYNODE,
		CPOSECONTROLLER,
		CPOSTPROCESSCONTROLLER,
		CPRECIPITATION,
		CPRECIPITATIONBLOCKER,
		CPREDICTEDVIEWMODEL,
		CPROP_HALLUCINATION,
		CPROPDOORROTATING,
		CPROPJEEP,
		CPROPVEHICLEDRIVEABLE,
		CRAGDOLLMANAGER,
		CRAGDOLLPROP,
		CRAGDOLLPROPATTACHED,
		CROPEKEYFRAME,
		CSCAR17,
		CSCENEENTITY,
		CSENSORGRENADE,
		CSENSORGRENADEPROJECTILE,
		CSHADOWCONTROL,
		CSLIDESHOWDISPLAY,
		CSMOKEGRENADE,
		CSMOKEGRENADEPROJECTILE,
		CSMOKESTACK,
		CSPATIALENTITY,
		CSPOTLIGHTEND,
		CSPRITE,
		CSPRITEORIENTED,
		CSPRITETRAIL,
		CSTATUEPROP,
		CSTEAMJET,
		CSUN,
		CSUNLIGHTSHADOWCONTROL,
		CTEAM,
		CTEAMPLAYROUNDBASEDRULESPROXY,
		CTEARMORRICOCHET,
		CTEBASEBEAM,
		CTEBEAMENTPOINT,
		CTEBEAMENTS,
		CTEBEAMFOLLOW,
		CTEBEAMLASER,
		CTEBEAMPOINTS,
		CTEBEAMRING,
		CTEBEAMRINGPOINT,
		CTEBEAMSPLINE,
		CTEBLOODSPRITE,
		CTEBLOODSTREAM,
		CTEBREAKMODEL,
		CTEBSPDECAL,
		CTEBUBBLES,
		CTEBUBBLETRAIL,
		CTECLIENTPROJECTILE,
		CTEDECAL,
		CTEDUST,
		CTEDYNAMICLIGHT,
		CTEEFFECTDISPATCH,
		CTEENERGYSPLASH,
		CTEEXPLOSION,
		CTEFIREBULLETS,
		CTEFIZZ,
		CTEFOOTPRINTDECAL,
		CTEFOUNDRYHELPERS,
		CTEGAUSSEXPLOSION,
		CTEGLOWSPRITE,
		CTEIMPACT,
		CTEKILLPLAYERATTACHMENTS,
		CTELARGEFUNNEL,
		CTEMETALSPARKS,
		CTEMUZZLEFLASH,
		CTEPARTICLESYSTEM,
		CTEPHYSICSPROP,
		CTEPLANTBOMB,
		CTEPLAYERANIMEVENT,
		CTEPLAYERDECAL,
		CTEPROJECTEDDECAL,
		CTERADIOICON,
		CTESHATTERSURFACE,
		CTESHOWLINE,
		CTESLA,
		CTESMOKE,
		CTESPARKS,
		CTESPRITE,
		CTESPRITESPRAY,
		CTEST_PROXYTOGGLE_NETWORKABLE,
		CTESTTRACELINE,
		CTEWORLDDECAL,
		CTRIGGERPLAYERMOVEMENT,
		CTRIGGERSOUNDOPERATOR,
		CVGUISCREEN,
		CVOTECONTROLLER,
		CWATERBULLET,
		CWATERLODCONTROL,
		CWEAPONAUG,
		CWEAPONAWP,
		CWEAPONBASEITEM,
		CWEAPONBIZON,
		CWEAPONCSBASE,
		CWEAPONCSBASEGUN,
		CWEAPONCYCLER,
		CWEAPONELITE,
		CWEAPONFAMAS,
		CWEAPONFIVESEVEN,
		CWEAPONG3SG1,
		CWEAPONGALIL,
		CWEAPONGALILAR,
		CWEAPONGLOCK,
		CWEAPONHKP2000,
		CWEAPONM249,
		CWEAPONM3,
		CWEAPONM4A1,
		CWEAPONMAC10,
		CWEAPONMAG7,
		CWEAPONMP5NAVY,
		CWEAPONMP7,
		CWEAPONMP9,
		CWEAPONNEGEV,
		CWEAPONNOVA,
		CWEAPONP228,
		CWEAPONP250,
		CWEAPONP90,
		CWEAPONSAWEDOFF,
		CWEAPONSCAR20,
		CWEAPONSCOUT,
		CWEAPONSG550,
		CWEAPONSG552,
		CWEAPONSG556,
		CWEAPONSSG08,
		CWEAPONTASER,
		CWEAPONTEC9,
		CWEAPONTMP,
		CWEAPONUMP45,
		CWEAPONUSP,
		CWEAPONXM1014,
		CWORLD,
		DUSTTRAIL,
		MOVIEEXPLOSION,
		PARTICLESMOKEGRENADE,
		ROCKETTRAIL,
		SMOKETRAIL,
		SPOREEXPLOSION,
		SPORETRAIL,
	} ClassId;

	typedef enum Hitbox_e
	{
		HITBOX_MAX,
	} Hitbox;

	typedef enum Bone_e
	{
		BONE_UNKNOWN0,
		BONE_UNKNOWN1,
		BONE_UNKNOWN2,
		BONE_UNKNOWN3,
		BONE_UNKNOWN4,
		BONE_UNKNOWN5,
		BONE_UNKNOWN6,
		BONE_UNKNOWN7,
		BONE_HEAD,
		BONE_UNKNOWN9,
		BONE_UNKNOWN10,
		BONE_UNKNOWN11,
		BONE_UNKNOWN12,
		BONE_UNKNOWN13,
		BONE_UNKNOWN14,
		BONE_UNKNOWN15,
		BONE_UNKNOWN16,
		BONE_UNKNOWN17,
		BONE_UNKNOWN18,
		BONE_UNKNOWN19,
		BONE_UNKNOWN20,
		BONE_UNKNOWN21,
		BONE_UNKNOWN22,
		BONE_UNKNOWN23,
		BONE_UNKNOWN24,
		BONE_UNKNOWN25,
		BONE_UNKNOWN26,
		BONE_UNKNOWN27,
		BONE_UNKNOWN28,
		BONE_UNKNOWN29,
		BONE_UNKNOWN30,
		BONE_UNKNOWN31,
		BONE_UNKNOWN32,
		BONE_UNKNOWN33,
		BONE_UNKNOWN34,
		BONE_UNKNOWN35,
		BONE_UNKNOWN36,
		BONE_UNKNOWN37,
		BONE_UNKNOWN38,
		BONE_UNKNOWN39,
		BONE_UNKNOWN40,
		BONE_UNKNOWN41,
		BONE_UNKNOWN42,
		BONE_UNKNOWN43,
		BONE_UNKNOWN44,
		BONE_UNKNOWN45,
		BONE_UNKNOWN46,
		BONE_UNKNOWN47,
		BONE_UNKNOWN48,
		BONE_UNKNOWN49,
		BONE_UNKNOWN50,
		BONE_UNKNOWN51,
		BONE_UNKNOWN52,
		BONE_UNKNOWN53,
		BONE_UNKNOWN54,
		BONE_UNKNOWN55,
		BONE_UNKNOWN56,
		BONE_UNKNOWN57,
		BONE_UNKNOWN58,
		BONE_UNKNOWN59,
		BONE_UNKNOWN60,
		BONE_UNKNOWN61,
		BONE_UNKNOWN62,
		BONE_UNKNOWN63,
		BONE_UNKNOWN64,
		BONE_UNKNOWN65,
		BONE_UNKNOWN66,
		BONE_UNKNOWN67,
		BONE_UNKNOWN68,
		BONE_UNKNOWN69,
		BONE_UNKNOWN70,
		BONE_UNKNOWN71,
		BONE_UNKNOWN72,
		BONE_UNKNOWN73,
		BONE_UNKNOWN74,
		BONE_UNKNOWN75,
		BONE_UNKNOWN76,
		BONE_UNKNOWN77,
		BONE_UNKNOWN78,
		BONE_UNKNOWN79,
		BONE_UNKNOWN80,
		BONE_UNKNOWN81,
		BONE_MAX
	} Bone;

	//typedef struct GlowObject_t
	//{
	//	DWORD pEntity;
	//	Util::Vector4 m_vecColor;
	//	unsigned char unk1[4];
	//	float m_flVelocity;
	//	float m_flBloomAmount;
	//	unsigned char unk2[4];
	//	bool m_bRenderWhenOccluded;
	//	bool m_bRenderWhenUnoccluded;
	//	bool m_bFullBloomRender;
	//	unsigned char unk3[5];
	//	int m_nGlowStyle;
	//	unsigned char unk4[6];
	//} GlowObject;

	//typedef struct GlobalVars_t
	//{
	//	float realtime;
	//	int	framecount;
	//	float absoluteframetime;
	//	float absoluteframestarttimestddev;
	//	float curtime;
	//	float frametime;
	//	int maxClients;
	//	int tickcount;
	//	float interval_per_tick;
	//	float interpolation_amount;
	//	int	simTicksThisFrame;
	//	int	network_protocol;
	//	void* pSaveData;
	//	bool m_bClient;
	//	bool m_bRemoteClient;
	//	int nTimestampNetworkingBase;
	//	int nTimestampRandomizeWindow;
	//} GlobalVars;

	class CBase;
	class CPlayer;
	class CWeapon;
	class CGlowObjectManager;
	class CGlowObject;

	class CBase {
	public:
		int GetID ();
		std::string GetName ();
	};

	class CWeapon {
	public:
		static CWeapon* GetWeapon (int iIndex);
		int GetIndex ();
		int GetClip ();
		WeaponId GetID ();
		float GetNextPrimaryAttack ();
		bool InReload ();
		bool IsReloaded ();
	};

	class CPlayer {
	public:
		static CPlayer* GetPlayer (int iIndex);
		static CPlayer* GetLocalPlayer ();

		int GetIndex ();
		int GetFlags ();
		Team GetTeam ();
		int GetHealth ();
		int GetArmor ();
		Util::Vector3 GetBonePosition (Bone_e eBone);
		Util::Vector3 GetPosition ();
		Util::Vector3 GetVelocity ();
		Util::Vector3 GetViewOffset ();
		Util::Vector3 GetEyePosition ();
		Util::Vector3 GetAimPunch ();
		Util::Vector3 GetVisualPunch ();
		void SetVisualPunch (Util::Vector3 vPunch);
		int GetTick ();
		int GetGlowIndex ();
		int GetShotsFired ();
		int GetInCrosshair ();
		bool IsDormant ();
		bool IsDead ();
		bool IsSpotted ();
		void Spotted (bool bState);
		float GetFlashDuration ();
		void SetFlashDuration (float flFlashDuration);

		bool CanAttack ();

		CWeapon* GetCurrentWeapon ();
	};

	class CEngine{
	public:
		static Util::Vector3 GetViewAngle ();
		static void SetViewAngle (Util::Vector3 vAngle);

		static void Attack ();
		static void Attack2 ();
		static void Jump ();

		static bool GetJump ();
		static void SetJump (bool bState);
		static bool GetAttack ();
		static void SetAttack (bool bState);
		static bool GetAttack2 ();
		static void SetAttack2 (bool bState);

		static bool GetSendPacket ();
		static void SetSendPacket (bool bState);

		static bool IsAngleNAN (Util::Vector3 vAngle);
		static void AngleNormalizeClamp (Util::Vector3& vAngle);

		static Util::Vector3 CalculatePunchReduction (Util::Vector2 vPitch, Util::Vector2 vYaw);
		static Util::Vector3 CalculateSmoothAngle (Util::Vector3 vSrcAngle, Util::Vector3 vDstAngle, float smoothAmount);
		static Util::Vector3 CalculateAngle (Util::Vector3 vSrcPosition, Util::Vector3 vDstPosition);
		static bool IsInFOV (Util::Vector3 vSrcPosition, Util::Vector3 vDstPosition, float flInFOV, float& flFOV);

		static bool RayTrace (Util::Vector3 leftBottom, Util::Vector3 rightTop, float& fDistance);

		template <typename _Ty> static _Ty Random (Util::Vector2 vRange);

		static void SetClanTag (const char* tag, const char* name);
	};

	template<typename _Ty>
	inline _Ty CEngine::Random (Util::Vector2 vRange)
	{
		if (vRange.m_flXPos == vRange.m_flYPos)
			return (_Ty)vRange.m_flXPos;

		std::random_device Random;
		std::mt19937 RandomGen (Random ());
		std::uniform_real<> randomDistribution (vRange.m_flXPos, vRange.m_flYPos);

		double result = randomDistribution (RandomGen);

		if (result > vRange.m_flYPos)
			result = vRange.m_flYPos;

		if (result < vRange.m_flXPos)
			result = vRange.m_flXPos;

		return (_Ty)result;
	}

	class CPlayerResource {
	public:
		static CPlayerResource* GetInstance ();
		CompetetiveTeammateColor GetCompetitiveTeammateColor (int iIndex);
	};

	class CGlowObject {
	public:
		CBase* GetEntity ();
		Util::Vector4 GetColor ();
		void SetColor (Util::Vector4 vColor);
		bool IsRenderWhenOccluded ();
		void SetRenderWhenOccluded (bool bState);
		bool IsRenderWhenUnoccluded ();
		void SetRenderWhenUnoccluded (bool bState);
		int GetGlowStyle ();
		void SetGlowStyle (int iStyle);
		float GetVelocity ();
		void SetVelocity (float flVelocity);
	};

	class CGlowObjectManager {
	public:
		static CGlowObjectManager* GetInstance ();
		int GetGlowObjectCount ();
		CGlowObject* GetGlowObject (int iIndex);
	};

	class CGlobalVars {
	public:
		static CGlobalVars* GetInstance ();
		int GetMaxClients ();
		int GetTickCount ();
		float GetIntervalPerTick ();
	};
}