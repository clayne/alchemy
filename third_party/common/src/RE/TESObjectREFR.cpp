#include "RE/TESObjectREFR.h"

#include "skse64/GameReferences.h"

#include <limits>

#include "RE/BSFixedString.h"
#include "RE/ExtraContainerChanges.h"
#include "RE/ExtraDataTypes.h"
#include "RE/ExtraFlags.h"
#include "RE/ExtraLock.h"
#include "RE/ExtraOwnership.h"
#include "RE/ExtraReferenceHandle.h"
#include "RE/ExtraTextDisplayData.h"
#include "RE/FormTraits.h"
#include "RE/InventoryChanges.h"
#include "RE/Misc.h"
#include "RE/NiNode.h"
#include "RE/Offsets.h"
#include "RE/TESActorBase.h"
#include "RE/TESFaction.h"
#include "RE/TESFullName.h"
#include "RE/TESNPC.h"
#include "RE/TESObjectCONT.h"
#include "REL/Relocation.h"


namespace RE
{
	NiPointer<TESObjectREFR> TESObjectREFR::LookupByHandle(RefHandle a_refHandle)
	{
		NiPointer<TESObjectREFR> ref;
		LookupReferenceByHandle(a_refHandle, ref);
		return ref;
	}


	bool TESObjectREFR::LookupByHandle(RefHandle a_refHandle, NiPointer<TESObjectREFR>& a_refrOut)
	{
		return LookupReferenceByHandle(a_refHandle, a_refrOut);
	}


	void TESObjectREFR::ActivateRefChildren(TESObjectREFR* a_activator)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::ActivateRefChildren)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::ActivateRefChildren);
		return func(this, a_activator);
	}


	RefHandle TESObjectREFR::CreateRefHandle()
	{
		RefHandle refHandle = *g_invalidRefHandle;
		if (GetRefCount() > 0) {
			RE::CreateRefHandle(refHandle, this);
		}
		return refHandle;
	}


	TESNPC* TESObjectREFR::GetActorOwner() const
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::ActorCharacter)) {
			return static_cast<TESNPC*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	TESBoundObject* TESObjectREFR::GetBaseObject() const
	{
		return baseForm;
	}


	float TESObjectREFR::GetBaseScale() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetBaseScale)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetBaseScale);
		return func(this);
	}


	TESContainer* TESObjectREFR::GetContainer() const
	{
		TESContainer* container = 0;
		if (baseForm) {
			switch (baseForm->formType) {
			case FormType::Container:
				container = static_cast<TESObjectCONT*>(baseForm);
				break;
			case FormType::NPC:
				container = static_cast<TESActorBase*>(baseForm);
				break;
			}
		}
		return container;
	}


	TESFaction* TESObjectREFR::GetFactionOwner() const
	{
		auto xOwnership = extraData.GetByType<ExtraOwnership>();
		if (xOwnership && xOwnership->owner && xOwnership->owner->Is(FormType::Faction)) {
			return static_cast<TESFaction*>(xOwnership->owner);
		} else {
			return 0;
		}
	}


	InventoryChanges* TESObjectREFR::GetInventoryChanges()
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetInventoryChanges)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetInventoryChanges);

		auto xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		auto changes = xContainerChanges ? xContainerChanges->changes : 0;
		if (!changes) {
			changes = func(this);
			if (changes) {
				changes->InitContainer();
				changes->GenerateLeveledListChanges();
			}
		}
		return changes;
	}


	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		return extraData.GetLinkedRef(a_keyword);
	}


	SInt32 TESObjectREFR::GetLockLevel() const
	{
		auto state = GetLockState();
		return state ? state->GetLockLevel(this) : -1 * std::numeric_limits<SInt32>::max();
	}


	LockState* TESObjectREFR::GetLockState() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetLockState)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetLockState);
		return func(this);
	}


	const char* TESObjectREFR::GetName() const
	{
		return baseForm ? baseForm->GetName() : "";
	}


	NiAVObject* TESObjectREFR::GetNodeByName(const BSFixedString& a_nodeName)
	{
		auto node = GetNiNode();
		return node ? node->GetObjectByName(a_nodeName) : 0;
	}


	UInt32 TESObjectREFR::GetNumItems(bool a_useDataHandlerChanges, bool a_arg2)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetNumItems)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetNumItems);
		return func(this, a_useDataHandlerChanges, a_arg2);
	}


	TESForm* TESObjectREFR::GetOwner() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetOwner)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetOwner);
		return func(this);
	}


	TESObjectCELL* TESObjectREFR::GetParentCell() const
	{
		return parentCell;
	}


	float TESObjectREFR::GetPositionX() const
	{
		return pos.x;
	}


	float TESObjectREFR::GetPositionY() const
	{
		return pos.y;
	}


	float TESObjectREFR::GetPositionZ() const
	{
		return pos.z;
	}


	const char* TESObjectREFR::GetReferenceName() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::GetReferenceName)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::GetReferenceName);
		return func(this);
	}


	float TESObjectREFR::GetWeight() const
	{
		return baseForm->GetWeight();
	}


	TESWorldSpace* TESObjectREFR::GetWorldspace() const
	{
		auto cell = parentCell;
		if (!cell) {
			cell = GetParentOrPersistentCell();
		}

		if (cell && cell->IsExteriorCell()) {
			return cell->worldSpace;
		} else {
			return 0;
		}
	}


	bool TESObjectREFR::HasCollision() const
	{
		return (flags & RecordFlags::kCollisionsDisabled) == 0;
	}


	bool TESObjectREFR::HasInventoryChanges() const
	{
		auto xContainerChanges = extraData.GetByType<ExtraContainerChanges>();
		auto changes = xContainerChanges ? xContainerChanges->changes : 0;
		return changes != 0;
	}


	bool TESObjectREFR::Is3DLoaded() const
	{
		return GetNiNode() != 0;
	}


	bool TESObjectREFR::IsActivationBlocked() const
	{
		auto xFlags = extraData.GetByType<ExtraFlags>();
		return xFlags && xFlags->IsActivationBlocked();
	}


	bool TESObjectREFR::IsDisabled() const
	{
		return (flags & RecordFlags::kInitiallyDisabled) != 0;
	}


	bool TESObjectREFR::IsLocked() const
	{
		auto state = GetLockState();
		return state && state->lockLevel > 0;
	}


	bool TESObjectREFR::IsMarkedForDeletion() const
	{
		return (flags & RecordFlags::kDeleted) != 0;
	}


	bool TESObjectREFR::IsOffLimits() const
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::IsOffLimits)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::IsOffLimits);
		return func(this);
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, const BSFixedString& a_nodeName)
	{
		auto node = a_target->GetNiNode();
		if (!node) {
			LOG_DMESSAGE("Cannot move the target because it does not have 3D");
			return false;
		}

		auto object = node->GetObjectByName(a_nodeName);
		if (!object) {
			LOG_DMESSAGE("Target does not have a node named %s", a_nodeName.c_str());
			return false;
		}

		return MoveToNode(a_target, object);
	}


	bool TESObjectREFR::MoveToNode(TESObjectREFR* a_target, NiAVObject* a_node)
	{
		auto& position = a_node->worldTransform.translate;
		NiPoint3 rotation;
		a_node->worldTransform.rotate.ToEulerAnglesXYZ(rotation);
		RefHandle handle = a_target->CreateRefHandle();
		MoveTo_Impl(handle, a_target->GetParentCell(), GetWorldspace(), position, rotation);
		return true;
	}


	void TESObjectREFR::PlayAnimation(NiControllerManager* a_manager, NiControllerSequence* a_toSeq, NiControllerSequence* a_fromSeq, bool a_arg4)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::PlayAnimation)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::PlayAnimation);
		return func(this, a_manager, a_toSeq, a_fromSeq, a_arg4);
	}


	void TESObjectREFR::SetActivationBlocked(bool a_blocked)
	{
		extraData.SetExtraFlags(ExtraFlags::Flag::kActivationBlocked, a_blocked);
	}


	void TESObjectREFR::SetCollision(bool a_enable)
	{
		if (a_enable) {
			flags &= ~RecordFlags::kCollisionsDisabled;
		} else {
			flags |= RecordFlags::kCollisionsDisabled;
		}
	}


	bool TESObjectREFR::SetDisplayName(const BSFixedString& a_name, bool a_force)
	{
		bool renamed = false;

		auto xTextData = extraData.GetByType<ExtraTextDisplayData>();
		if (xTextData) {
			bool inUse = xTextData->message || xTextData->owner;
			if (inUse && a_force) {
				xTextData->message = 0;
				xTextData->owner = 0;
			}
			renamed = !inUse || a_force;
			xTextData->SetName(a_name.c_str());
		} else {
			xTextData = new ExtraTextDisplayData(a_name.c_str());
			extraData.Add(xTextData);
			renamed = true;
		}

		return renamed;
	}


	bool TESObjectREFR::SetMotionType(MotionType a_motionType, bool a_allowActivate)
	{
		auto node = GetNiNode();
		if (!node) {
			LOG_DMESSAGE("Target does not have 3D");
			return false;
		}

		return node->SetMotionType(static_cast<UInt32>(a_motionType), true, false, a_allowActivate);
	}


	void TESObjectREFR::SetPosition(float a_x, float a_y, float a_z)
	{
		return SetPosition(NiPoint3(a_x, a_y, a_z));
	}


	void TESObjectREFR::SetPosition(NiPoint3 a_pos)
	{
		MoveTo_Impl(*g_invalidRefHandle, GetParentCell(), GetWorldspace(), a_pos, rot);
	}


	void TESObjectREFR::MoveTo_Impl(RefHandle& a_targetHandle, TESObjectCELL* a_targetCell, TESWorldSpace* a_selfWorldSpace, NiPoint3& a_position, NiPoint3& a_rotation)
	{
		using func_t = function_type_t<decltype(&TESObjectREFR::MoveTo_Impl)>;
		REL::Offset<func_t*> func(Offset::TESObjectREFR::MoveTo);
		return func(this, a_targetHandle, a_targetCell, a_selfWorldSpace, a_position, a_rotation);
	}
}
