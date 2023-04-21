#include "Player.h"
#include "cassert"
#include "ImGuiManager.h"

void Player::Initialize(Model* model, uint32_t textureHandle) { 
	assert(model);

	model_ = model;
	textureHandle_ = textureHandle;

	worldTransform_.Initialize();
	input_->GetInstance();

}

void Player::Update() { 

	Vector3 move = Vector3(0, 0, 0);

	const float kPlayerSpeed = 0.2f;

	if (input_->GetInstance()->PushKey(DIK_LEFT)) {
		move.x -= kPlayerSpeed;
	}

	if (input_->GetInstance()->PushKey(DIK_RIGHT)) {
		move.x += kPlayerSpeed;
	}

	if (input_->GetInstance()->PushKey(DIK_UP)) {
		move.z += kPlayerSpeed;
	}

	if (input_->GetInstance()->PushKey(DIK_DOWN)) {
		move.z -= kPlayerSpeed;
	}

	worldTransform_.translation_ += move;

	worldTransform_.matWorld_ = Matrix4x4::MakeAffineMatrix(worldTransform_.scale_, worldTransform_.rotation_, worldTransform_.translation_);

	worldTransform_.TransferMatrix();
}

void Player::Draw(const ViewProjection& viewProjection) {

	model_->Draw(worldTransform_, viewProjection,textureHandle_);

}