// ==UserScript==
// @name         Form Filler
// @namespace    http://tampermonkey.net/
// @version      1.0
// @description  Paste single line with values separated by " - "
// @match        https://urios.neolms.com/quiz_question_bank/new_question
// @grant        none
// ==/UserScript==

(function () {
  "use strict";

  const data = prompt(
    'Paste single line (" - " separates question from options):',
  );
  if (!data) return;

  const values = data.split(" - ").map((s) => s.trim());

  const fields = [
    "#question_description",
    "#text_1",
    "#text_2",
    "#text_3",
    "#text_4",
  ];

  fields.forEach((sel, i) => {
    const el = document.querySelector(sel);
    if (el && values[i]) el.value = values[i];
  });
})();
