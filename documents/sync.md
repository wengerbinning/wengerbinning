在Linux中，为提高磁盘的写入数据的效率，会将写入的数据暂时保存在FS缓存中，若此时断电，则会导致该数据丢失；sync用于将FS缓存中的数据强制写入磁盘中。