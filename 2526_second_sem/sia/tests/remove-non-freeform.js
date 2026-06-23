// ==UserScript==
// @name         Remove Non-Freeform Questions
// @namespace    http://tampermonkey.net/
// @version      1.0
// @description  Removes all non-freeform questions from the grading page
// @match        https://urios.neolms.com/teacher_quiz_assignment/grade/*
// @grant        none
// ==/UserScript==

(function () {
  "use strict";

  function removeNonFreeform() {
    const form = document.getElementById("grade_form");
    if (!form) return;

    const h2s = Array.from(form.querySelectorAll(":scope > h2"));

    for (let i = h2s.length - 1; i >= 0; i--) {
      const h2 = h2s[i];

      let isFreeform = false;
      let el = h2.nextElementSibling;
      while (
        el &&
        el.tagName !== "H2" &&
        !el.classList.contains("optionsRibbon")
      ) {
        if (el.querySelector(".pencil")) {
          isFreeform = true;
          break;
        }
        el = el.nextElementSibling;
      }

      if (isFreeform) continue;

      const toRemove = [h2];
      let next = h2.nextElementSibling;
      while (
        next &&
        next.tagName !== "H2" &&
        !next.classList.contains("optionsRibbon")
      ) {
        const nextSibling = next.nextElementSibling;
        toRemove.push(next);
        next = nextSibling;
      }
      toRemove.forEach((n) => n.remove());
    }
  }

  document.addEventListener("DOMContentLoaded", removeNonFreeform);
})();
