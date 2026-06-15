# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head.next==None:
            return None

        slow = fast = temp = head

        while fast!= None and fast.next !=None:
            temp = slow
            slow = slow.next
            fast = fast.next.next
        
        temp.next = slow.next
        slow.next = None

        return head

        