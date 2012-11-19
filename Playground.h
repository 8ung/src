#include <vector>


class Playground {

private:
	Position_class upper_left_corner;
	Position_class bottom_right_corner;
	int turn_ratio = 2;
public:
	std::vector<int> powerup_vector;
	std::vector<Worm> worm_vector;
	std::vector<Worm> survivor_vector;

	Playground();

private:
	void random_worm_values();

	void random_power_up_values();

	void collision();

	bool round_finished();

public:
	void update(std::vector<int> pressed_keys);

	void initialize(Uint32 colour, unsigned int left_control, unsigned int right_control);
};
