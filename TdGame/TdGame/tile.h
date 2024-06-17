#ifndef __TILE_H__
#define __TILE_H__

#include <vector>

#define SIZE_TILE 48

struct  Tile
{
	enum class Direction
	{
		None,
		Up,
		Down,
		Left,
		Right
	};
	int terrian = 0;		//����
	int decoration = -1;	//װ��
	int special_flag = -1;	//�����־
	bool has_tower = false;	//��ǰ�Ƿ��ѷ��÷�����
	Direction direction = Direction::None;	//����
};

typedef std::vector<std::vector<Tile>> TileMap;

#endif // !__TILE_H__
