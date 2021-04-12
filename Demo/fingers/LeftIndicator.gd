extends CSGSphere


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

export(String, "right_index", "left_index") var index_action
export(String, "left_major", "right_major") var major_action

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if   Input.is_action_pressed("left_index"):
		material.albedo_color = Color(1, 0, 0, 1)
	elif Input.is_action_pressed("left_major"):
		material.albedo_color = Color(0, 1, 0, 1)
	else:
		material.albedo_color = Color(1, 1, 1, 1)
