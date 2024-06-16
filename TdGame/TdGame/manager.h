#ifndef __MANAGER_H__
#define __MANAGER_H__

template <typename T>
class Manager
{
public:
	static T* instance()
	{
		if (!manager)
			manager = new T();
		return manager;
	}

protected:
	Manager() = default;
	~Manager() = default;
	Manager(const Manager&) = delete;
	Manager& operator=(const Manager&) = delete;

private:
	static T* manager;
};

template <typename T>
T* Manager<T>::manager = nullptr;

#endif // __MANAGER_H__

