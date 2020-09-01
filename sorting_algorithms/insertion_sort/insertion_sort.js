function insertion(data) {
	// iterate through elements comparing the current element to its predecessors

	// 10, 9, 3, 3, 7, 8, 6, 11, 2
	for (let i = 1; i < data.length; i++) {
		if (data[i] < data[i - 1]) {
			let insert_position = i - 1;
			let temp = data[i];

			while (temp < data[insert_position]) {
				data[insert_position] = data[insert_position + 1]; // shift values by 1
				insert_position--;
				console.log(data, insert_position);
			}

			data[insert_position] = temp;
		}
	}
}

insertion([10, 9, 3, 3, 7, 8, 6, 11, 2]);
