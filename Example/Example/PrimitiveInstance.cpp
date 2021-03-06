#include "PrimitiveInstance.h"

void PrimitiveInst::TranslateAbsolute(float x, float y, float z){
	XMatTranslation(Position, x, y, z);
}

void PrimitiveInst::RotateXAbsolute(float ang) {
	XMatRotationX(RotationX, Deg2Rad(ang));
}

void PrimitiveInst::RotateYAbsolute(float ang) {
	XMatRotationY(RotationY, Deg2Rad(ang));
}

void PrimitiveInst::RotateZAbsolute(float ang) {
	XMatRotationZ(RotationZ, Deg2Rad(ang));
}

void PrimitiveInst::ScaleAbsolute(float sc) {
	XMatScaling(Scale,sc,sc,sc);
}

void PrimitiveInst::TranslateRelative(float x, float y, float z) {
	XMATRIX44 tmp;
	XMatTranslation(tmp, x, y, z);
	Position *= tmp;
}

void PrimitiveInst::RotateXRelative(float ang) {
	XMATRIX44 tmp;
	XMatRotationX(tmp, Deg2Rad(ang));
	RotationX *= tmp;
}

void PrimitiveInst::RotateYRelative(float ang) {
	XMATRIX44 tmp;
	XMatRotationY(tmp, Deg2Rad(ang));
	RotationY *= tmp;
}

void PrimitiveInst::RotateZRelative(float ang) {
	XMATRIX44 tmp;
	XMatRotationZ(tmp, Deg2Rad(ang));
	RotationZ *= tmp;
}

void PrimitiveInst::ScaleRelative(float sc) {
	XMATRIX44 tmp;
	XMatScaling(tmp, sc, sc, sc);
	Scale *= tmp;
}

void PrimitiveInst::Update() {
	Final = Scale*RotationX*RotationY*RotationZ*Position;
}

void PrimitiveInst::Draw(){
	if (!Visible)
		return;
	pBase->Draw(&Final.m[0][0],&(*pViewProj).m[0][0]);
}
