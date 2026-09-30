#include "MyMaxHeap.h"
#include <iostream>
#include <vector>

using namespace std;

void printRequest(const RentalRequest& r) {
    cout << r.bookingId
         << " | " << r.customerId
         << " | " << r.carId
         << " | Tier: " << r.membershipTier
         << " | Time: " << r.bookingTimestamp << endl;
}

int main() {
    MyMaxHeap heap;

    vector<RentalRequest> requests = {
        {"RENT_001", "CUS_001", "CAR_01", 1, 1690000005},
        {"RENT_002", "CUS_002", "CAR_01", 2, 1690000002},
        {"RENT_003", "CUS_003", "CAR_01", 3, 1690000004},
        {"RENT_004", "CUS_004", "CAR_01", 3, 1690000001},
        {"RENT_005", "CUS_005", "CAR_01", 2, 1690000003}
    };

    cout << "===== RF2 - BUILD HEAP =====" << endl;

    heap.BuildHeap(requests);

    cout << "Yeu cau uu tien nhat: ";
    printRequest(heap.Top());

    cout << endl;
    cout << "===== RF2 - REMOVE BY ID =====" << endl;

    if (heap.RemoveById("RENT_002")) {
        cout << "Da xoa RENT_002" << endl;
    }

    cout << endl;
    cout << "===== RF2 - XU LY THEO THU TU UU TIEN =====" << endl;

    int order = 1;

    while (!heap.Empty()) {
        RentalRequest request = heap.ExtractMax();

        cout << order << ". ";
        printRequest(request);

        order++;
    }

    return 0;
}
